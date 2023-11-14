#include <stdio.h>
#define douinc(a) a * 2 + 1
struct x
{
    char c;
    int a;
};
union y
{
    char c;
    int a;
};

int YourMod(int a, int b)
{
    int ans = 0;
    ans = a & (0x07);
    return ans;
}
int isMultipleOf3(int n)
{
    int ans = 0;
    while(n)
    {
        ans += n&1;
        n>>=1;
        ans -= n&1;
        n>>=1;    
    }
    return !(ans);
}
int main()
{
    int ans = isMultipleOf3(10);
    // int a=douinc(3);
    // struct x b = {'a', 10};
    // union y c = {'a', 10};
    // // printf("a=%d\n", a);
    // printf("b=%ld\n", sizeof(b));
    // printf("c=%ld\n", sizeof(c));
    // int a=0x0001, b=0x1100;
    // printf("a:0x%x, b:0x%x\n", a, b);
    // printf("a && b :0x%x\n", (a&&b));
    // printf("a & b :0x%x\n", (a&b));
    // printf("a || b :0x%x\n", (a||b));
    // printf("a | b :0x%x\n", (a|b));
    printf("mod ans=%d\n", ans);
    return 0;
}