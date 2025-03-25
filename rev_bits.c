#include <unistd.h>

unsigned char	swab_bits(unsigned char octet)
{
    return ((octet << 4) | (octet >> 4 )) ;
}

void	rev_bits(unsigned char octet)
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
    char c = 2;
    rev_bits(swab_bits(c));
    return 0;
}