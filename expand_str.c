#include <unistd.h>

void expand_str(char *str)
{
    int i = 0;
    int j = 0;
    int count = 0;
    char sp = ' ';
    while (str[i] == ' ')
        i++;
    while (str[i])
    {
        if (str[i] != ' ')
            write(1, &str[i], 1);
        if (str[i] == ' ')
            count++;
        if ( str[i + 1] == '\0')
            break;
        if(str[i] == ' ' && str[i + 1] != ' ' )
        {
           
                write(1, &sp, 1);
                write(1, &sp, 1);
                write(1, &sp, 1);
         
                count = 0;
        }

        i++;
    }

    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        expand_str(argv[1]);
    }
    else
    {
        write(1, "\n", 1);
    }
}