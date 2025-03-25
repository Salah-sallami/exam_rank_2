

unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int n;
    if (a == 0 || b == 0)
        return 0;
    if( a > b)
        n = a;
    else 
        n = b;
    while (1)
    {
        if(n % a == 0 && n % b == 0)
            return n;
        n++;
    }
    
}

int	 main(void)
{
		int	 x = 15;
		int	 y = 10;

		printf("LCM of %d and %d is %d\n", x, y, lcm(x, y));
		return (0);
}