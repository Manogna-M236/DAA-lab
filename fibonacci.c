#include <stdio.h>

int f(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    else
        return f(n - 1) + f(n - 2);
}

int main()
{
    int n;

    printf("Enter the value of n:\n");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Error!!\n");
        return 0;
    }

    f(n);

    printf("Fibonacci term is:\n%d", f(n));

    return 0;
}
