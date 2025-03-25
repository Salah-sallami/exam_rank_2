#include "stdio.h"

int max(int *tab, unsigned int len)
{
    if (len == 0)
        return 0;
    int max = tab[len - 1];
    // int i = 1 ;

    while (len--)
    {
        if (tab[len] > max)
            max = tab[len];
    }

    return max;
}
int main()
{
    int tab[] = {553 ,532 ,883};
    printf("%d\n", max(tab, 3));
} 