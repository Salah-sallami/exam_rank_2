#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int check_doubel(char *str1, char c, int index)
{
    int i = index - 1;
    while (str1[i])
    {
        if (str1[i] == c)
            return 0;
        i--;
    }
    return 1;
}

int check_doubel_2(char *str1, char c, int index, char *str2)
{
    int i = index - 1;
    while (str2[i])
    {
        if(str2[i] == c)
            return 1;
        i--;
    }


    i = 0 ;

    while (str1[i])
    {
        if(str1[i] == c)
            return 0;
        i++;
    }
    

    return 1 ;
}

void inter(char *str1, char *str2)
{

    int i = 0;

    while (str1[i])
    {
        if (check_doubel(str1, str1[i], i))
            write(1, &str1[i], 1);
        i++;
    }

    i = 0;

    while (str2[i])
    {
        if (check_doubel_2(str1, str2[i], i, str2) && check_doubel(str2, str2[i], i))
            write(1, &str2[i], 1);
        i++;
    }
}

int main()
{
    char *str1 = "zpadinton"; 
    char *str2 = "paqefwtdjetyiytjneytjoeyjnejeyj";
    inter(str1, str2);
    return 0;
}