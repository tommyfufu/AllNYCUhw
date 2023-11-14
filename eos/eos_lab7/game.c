#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

typedef struct
{
    int guess;
    char result[8];
} data_t;
int shmid;
data_t *shm;
int ans;

void handler(int signo, siginfo_t *info, void *context)
{
    memset(shm->result, 0, 8);
    if(signo == SIGUSR1)
    {
        
        if(shm->guess > ans)
        {
            
            strcpy(shm->result, "smaller");
            printf("Guess: %d, %s\n", shm->guess, shm->result);
            kill(info->si_pid, SIGUSR1);
        }
        else if(shm->guess < ans)
        {
            strcpy(shm->result, "bigger");
            printf("Guess: %d, %s\n", shm->guess, shm->result);
            kill(info->si_pid, SIGUSR1);
        }
        else
        {
            strcpy(shm->result, "bingo");
            printf("Guess: %d, %s\n", shm->guess, shm->result);
            kill(info->si_pid, SIGUSR1);
        }

    }
    if(signo == SIGINT)
    {
        shmdt(shm);
        ans=shmctl(shmid, IPC_RMID, NULL);
        if(ans<1)
        {
            fprintf(stderr,"remove share memory failed\n");
            exit(1);
        }
        exit(0);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("game useage: ./game <key> <guess>\n");
        exit(1);
    }
    
    
    key_t key;
    data_t our_data;
    pid_t my_pid;    
    int retval;
    struct sigaction my_action;
    my_pid = getpid();
    printf("Game PID: %d\n", my_pid);
    key = atoi(argv[1]);

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
    printf("Server create share mem, line: %d\n", __LINE__);

    ans = atoi(argv[2]);
    memset(shm->result, 0, 8);

    memset(&my_action, 0, sizeof(struct sigaction));
    my_action.sa_flags = SA_SIGINFO;
    my_action.sa_sigaction = handler;

    sigaction(SIGUSR1, &my_action, NULL);
    struct timespec req;
    memset(&req, 0, sizeof(struct timespec));
    req.tv_sec = 15;
    req.tv_nsec = 0;
    
    do{
        retval = nanosleep(&req, &req);
    }while(retval);

    return 0;
}