#include <stdio.h>

void toh(int n, char S, char D, char A)
{
    if (n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, S, D);
        return;
    }

    toh(n - 1, S, A, D);
    printf("Move disk %d from %c to %c\n", n, S, D);
    toh(n - 1, A, D, S);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nRequired moves:\n");
    toh(n, 'S', 'D', 'A');

    return 0;
}
