#include <stdio.h>
#include <stdlib.h>
#define SUM(a, b) a + b
int check_mut_of_five(int num)
{
    int num2;
    num2 = num * 2;
    num2 = num2 * 0.1 * 10;
    // num2 = num2 * 10;
    if (num2 == (num * 2))
        return 1;
    else
        return 0;
}
int main()
{
    int ret, in;

    // while (scanf("%d", &in) != EOF)
    // {
    //     ret = check_mut_of_five(in);
    //     printf("ret is %d\n", ret);
    // }
    printf("SUM(a+b)*10 = %d\n", SUM(2, 5) * 10);
    printf("(SUM(a+b))*10 = %d\n", (SUM(2, 5)) * 10);

    return 0;
}