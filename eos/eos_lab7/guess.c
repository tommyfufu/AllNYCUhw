#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>

typedef struct
{
    int guess;
    char result[8];
} data_t;
int shmid;
data_t *shm;
pid_t game_pid;

void handler(int signo, siginfo_t *info, void *context)
{

    if (signo == SIGUSR1)
    {
        printf("Guess: %d\n", shm->guess);
        int retval;

        if ((retval = strcmp(shm->result, "smaller")) == 0)
            shm->guess /= 2;
        if ((retval = strcmp(shm->result, "bigger")) == 0)
            shm->guess *= 2;
        if ((retval = strcmp(shm->result, "bingo")) == 0)
        {
            shmdt(shm);
            shmctl(shmid, IPC_RMID, NULL);
            exit(0);
        }
    }
}
void timer_handler(int signo)
{
    kill(game_pid, SIGUSR1);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("./guess <key> <upper_bound> <pid>\n");
        exit(1);
    }

    key_t key;
    data_t our_data;
    struct sigaction my_action, time_action;
    struct itimerval timer;

    key = atoi(argv[1]);
    game_pid = atoi(argv[3]);
    if ((shmid = shmget(key, sizeof(our_data), IPC_CREAT | 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }

    // SIGUSER1 for adjust guess number
    memset(&my_action, 0, sizeof(struct sigaction));
    my_action.sa_flags = SA_SIGINFO;
    my_action.sa_sigaction = handler;
    sigaction(SIGUSR1, &my_action, NULL);

    // timer for sending kill to game every one sec
    memset(&time_action, 0, sizeof(struct sigaction));
    time_action.sa_handler = timer_handler;
    sigaction(SIGVTALRM, &time_action, NULL);

    int my_guess = atoi(argv[2]);
    shm->guess = my_guess;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1)
        ;
    return 0;
}