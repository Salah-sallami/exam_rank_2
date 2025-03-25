#include <stdio.h>
#include <stdlib.h>

int len_digt(int nbr)
{
    int len = 0;
    if (nbr < 0)
    {
        nbr *= -1;
        len++;
    }
    while (nbr >= 10)
    {
        len++;
        nbr = nbr / 10;
    }
    len++;

    return len;
}

char *ft_itoa(int nbr)
{
    int n = nbr;
    int sign = 1;

    char *p;
    int len = len_digt(nbr);
    printf("%d\n", len);

    p = malloc(sizeof(char) * (len + 1));
    if (nbr == 0)
    {
        p[0] = '0';
        return p;
    }
    if (nbr < 0)
    {
        p[0] = '-';
        n *= -1;
    }
    p[len] = '\0';

    // len--;
    while (n)
    {
        p[len - 1] = n % 10 + '0';
        n /= 10;
        len--;
    }

    return p;
}

int main()
{
    char *p = ft_itoa(0);
}