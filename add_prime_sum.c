#include <stdio.h>

int add_prime_sum(int n) // 5
{
    int sum = 0;
    int z;
    int i = n ; // 5
    int j;
    while (i > 1) // 5 > 1
    {
        j = i;  // 5  
        z = i - 1; // 4
        while (z > 1) // 4 > 1
        {
            if (j % z == 0) // 4 % 2 == 0
            {
                break;
            }
            z--;
        }
        if (z == 1)
            sum += j;
        i--;
    }

    return sum ;
}

int main()
{
    int n = 42;
    printf("%d\n", add_prime_sum(n));
}