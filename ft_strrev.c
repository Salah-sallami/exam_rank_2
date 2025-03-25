#include <stdio.h>

size_t  ft_strlen(const char *str)
{
    size_t i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char    *ft_strrev(char *str)
{
    char tmp ;
    int i = 0;
    int len = ft_strlen(str) - 1;

    while (i < len)
    {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp ;
        i++;
        len--;
    }

    return str;
    
}

int main(int argc, char const *argv[])
{
    while(*++argv)
    {
        printf("%s\n", ft_strrev((char *)*argv));
    }
    return 0;
}