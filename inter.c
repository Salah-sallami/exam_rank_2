#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int check_doubel(char *str1, char c, int index , char *str2)
{
    int i = index - 1;
    while (str1[i])
    {
        if(str1[i] == c)
            return 0;
        i--;
    }


    i = 0 ;

    while (str2[i])
    {
        if(str2[i] == c)
            return 1;
        i++;
    }
    

    return 0 ;
}

void inter(char *str1, char *str2)
{

    int i = 0;

    while (str1[i])
    {
        if (check_doubel(str1, str1[i], i ,str2))
            write(1,&str1[i],1);
        i++;
    }

}

int main()
{
    char *str1 = "rien"; // rien
    char *str2 = "cette phrase ne cache rien";
    inter(str1, str2);
    return 0;
}