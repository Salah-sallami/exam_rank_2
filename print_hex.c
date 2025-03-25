#include <unistd.h>


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

void print_hex(int nbr)
{
    if(nbr >= 16)
    {
        print_hex(nbr / 16);
    }
    char *base = "0123456789abcdef";
    nbr = base[nbr % 16];
    write(1,&nbr,1);
}


int main(int ac, char **av)
{
    if (ac == 2)
        print_hex(ft_atoi(av[1]));
    else
        write(1,"\n",1);
}