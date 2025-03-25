#include <stdio.h>
#include <stdlib.h>

void fprime(int n)
{
    int pr = 2;
    int i;
    int x;

    i = n - 1;
    x = n;
    if (n <= 0)
    {
        printf("\n");
        return;
    }
    while (i > 1)
    {
        if (x % i == 0)
        {
            break;
        }
        i--;
    }
    if (i <= 1)
    {
        printf("%d", n);
        return;
    }

    while (1)
    {
        if (n % pr == 0)
        {
            printf("%d*", pr);
            n = n / pr;

            i = n - 1;
            x = n;

            while (i > 1)
            {
                if (x % i == 0)
                {
                    break;
                }
                i--;
            }
            if (i == 1)
            {
                printf("%d", n);
                break;
            }
        }
        else
        {
            i = pr - 1;
            x = pr;
            pr++;

            while (i > 1)
            {
                if (x % i == 0)
                {
                    break;
                }
                i--;
            }
        }
    }
    printf("\n");
}

int main(int ac, char **av)
{
    if (ac == 2)
        fprime(atoi(av[1]));
    else
        printf("\n");
    return 0;
}