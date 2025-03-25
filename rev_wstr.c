#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int delimiter(char c)
{
    return (c == ' ');
}

int wc(char *s)
{
    int inword = 0;
    int count = 0;
    while (*s)
    {
        if (*s != ' ' && inword == 0)
        {
            inword = 1;
            count++;
        }
        else if (*s == ' ')
            inword = 0;
        s++;
    }
    return (count);
}

char **ft_split(char *str)
{
    int wordcount = wc(str);
    char **array = (char **)malloc((wordcount + 1) * sizeof(char *));
    int i = 0;

    if (!array)
        return (NULL);

    while (*str)
    {
        // Skip leading whitespace
        while (delimiter(*str))
            str++;
        // Break if end of string
        if (*str == '\0')
            break;
        // Account for the start of a word
        char *start = str;
        // Find the word length
        while (!delimiter(*str) && *str)
            str++;
        int len = str - start;
        // Allocate memory in array
        array[i] = (char *)malloc((len + 1) * sizeof(char));
        // Copy the current word from start to result[i]
        int word = 0;
        while (word < len)
        {
            array[i][word] = start[word];
            word++;
        }
        // Null terminate and move to next word/array
        array[i][word] = '\0';
        i++;
    }
    array[i] = NULL;
    return (array);
}
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
void rev_wstr(char *s)
{
    char **p = ft_split(s);
    int wordcount = wc(s) - 1;
    int len = wc(s) - 1;

    while (wordcount >= 0)
    {
        if (wordcount != len)
            ft_putstr(" ");
        ft_putstr(p[wordcount]);
        wordcount--;
    }
}

int main(void)
{
    char *s = "You";
    rev_wstr(s);

    return (0);
}