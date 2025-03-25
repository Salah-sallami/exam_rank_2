// int ft_isblank(char c)
// {
// 	if (c <= 32)
// 		return (1);
// 	return (0);
// }

// int		ft_isvalid(char c, int base)
// {
// 	char digits[17] = "0123456789abcdef";
// 	char digits2[17] = "0123456789ABCDEF";

// 	while (base--)
// 		if (digits[base] == c || digits2[base] == c)
// 			return (1);
// 	return (0);
// }

// int		ft_value_of(char c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (c - '0');
// 	else if (c >= 'a' && c <= 'f')
// 		return (c - 'a' + 10);
// 	else if (c >= 'A' && c <= 'F')
// 		return (c - 'A' + 10);
// 	return (0);
// }

// int		ft_atoi_base(const char *str, int str_base)
// {
// 	int result;
// 	int sign;

// 	result = 0;
// 	while (ft_isblank(*str))
// 		str++;
// 	sign = (*str == '-') ? -1 : 1;
// 	(*str == '-' || *str == '+') ? ++str : 0;
// 	while (ft_isvalid(*str, str_base))
// 		result = result * str_base + ft_value_of(*str++);
// 	return (result * sign);
// }
// Uncomment the main to test the function

int	ft_atoi_base(const char *str, int base)
{
	int sing = 1;
	int value = 0;
	int result = 0;
	
	if(*str == '-')
	{
		sing = -1;
		str++;
	}
	while (*str)
	{
		if(*str >= '0' && *str <= '9')
			value = *str - '0';
		else if(*str >= 'A' && *str <= 'F')
			value = *str - 'A' + 10 ;
		else if(*str >= 'a' && *str <= 'f')
			value = *str - 'a' + 10 ;
		else
			break;
		
		if(value >= base)
			break;
		
		result = ( result * base ) + value;
		str++;

	}
	return (result * sing);
	
}




// int main(void)
// {
//     printf("%d\n", ft_atoi_base("19", 16));
// 	return (0);
// }

#include <stdio.h>
int	main()
{
    printf("%d\n", ft_atoi_base("ff",16));
}