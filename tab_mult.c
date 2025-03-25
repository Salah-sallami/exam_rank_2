#include <unistd.h>
#include <stdlib.h>

int ft_atoi(char *s)
{
    int sing = 1;
    int i = 0;
    int sum = 0;
    if (s[i] == '+')
    {
        sing = 1;
        i++;
    }
    if (s[i] == '-')
    {
        sing *= -1;
        i++;
    }
    while (s[i])
    {
        sum = sum * 10 + s[i] - 48;
        i++;
    }
    return (sum * sing);
    
}

void ft_putnbr(int nbr)
{
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    char c = nbr % 10 + '0';
    write(1, &c, 1);
}

void mult(char *nmbr)
{
    int nmb = ft_atoi(nmbr);
    int i = 1;
    int sum = 0;
    int c;
    while (i < 10)
    {
        sum = i * nmb;
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(nmb);
        write(1, " = ", 3);
        ft_putnbr(sum);

        write(1, "\n", 1);
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        mult(argv[1]);
    }
    else
    {
        write(1, "\n", 1);
    }
}