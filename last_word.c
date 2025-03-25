#include <unistd.h>

int ft_strlen(char *s)
{
    int len = 0;
    while (s[len])
        len++;
    return (len - 1);
}
void last(char *str)
{
    int i = ft_strlen(str);
    while (str[i] == ' ')
        i--;
    while (str[i])
    {
        if(str[i] == ' ')
            break;
        i--;
    }
    i++;
    while (str[i])
    {
        if(str[i] == ' ')
            break;
        write(1,&str[i],1);
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc , char **argv)
{
        if (argc == 2)
    {
        last(argv[1]);
    }
    else
    {
        write(1, "\n", 1);
    }
}