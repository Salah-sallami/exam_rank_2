#include "stdio.h"

int pcgd(int a, int b)
{
    int tmp;

    if (a > b)
    {
        tmp = a % b;
        if (tmp == 0)
            return b;
        return pcgd(b, tmp);
    }
    else
    {
        tmp = b % a;
        if (tmp == 0)
            return a;
        return pcgd(a, tmp);
    }
}

int main()
{
    printf("%d\n", pcgd(42, 42));
    printf("%d\n", pcgd(42, 12));
    printf("%d\n", pcgd(14, 77));
    printf("%d\n", pcgd(17, 3));
}