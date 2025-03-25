#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int bit = 8;
    unsigned char c;
    while (bit--)
    {
        c = (octet >> bit & 1) + '0';
        write(1,&c,1);  
    }
}

int main(int argc, char const *argv[])
{
    print_bits(2);
    return 0;
}