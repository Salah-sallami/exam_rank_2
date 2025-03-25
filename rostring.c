#include <unistd.h>
#include <stdlib.h>

void rot(char *s)
{
    int i = 0;
    int j = 0;
    int start = 0;
    char c = ' ';
    char *p;
    while (s[i] == ' ' || s[i] == '\t')
        i++;

        start = i;
        while (s[i] && s[i] != ' ' && s[i] != '\t')
            i++;
        p = malloc(sizeof(char) * (i - start + 1));
        while (j < (i - start))
        {
            p[j] = s[start + j];
            j++;
        }
        p[j] = '\0';

    while (s[i] == ' ' || s[i] == '\t')
        i++;
    int vld = 0;
    while (s[i])
    {
        
        if (s[i] != ' ' && s[i] != '\t')
        {
            write(1, &s[i], 1);
            vld = 1;
        }
        if ((s[i + 1] == ' ' || s[i + 1] == '\t' || s[i + 1] == '\0') && vld == 1)
        {
            write(1, &c, 1);
            vld = 0;
        }
        i++;
    }
    i = 0;
    while (p[i])
    {
        write(1, &p[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        rot(argv[1]);
    }
    else
    {
        write(1, "\n", 1);
    }
}
