int isMultipleOf3(int n)
{
    int odd_count = 0;
    int even_count = 0;
    if (n < 0)
        n = -n;
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    while (n)
    {
        if (n & 1)
            odd_count += 1;
        n = n >> 1;
        if (n & 1)
            even_count += 1;
        n = n >> 1;
    }
    return isMultipleOf3(abs(odd_count - even_count));
}
int main()
{
    int num = 81;
    if (isMultipleOf3(num))
        printf("multiple of 3");
    else
        printf("not a multiple of 3");
}