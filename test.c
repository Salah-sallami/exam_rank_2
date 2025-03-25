void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i]; 
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

#include <stdio.h>

int main(void) 
{
	int arr[] = {5, 2, 8, 1, 3};
	unsigned int size = sizeof(arr) / sizeof(arr[0]);

	printf("Before sorting: ");
	unsigned int i = 0;
	while (i < size) 
	{
		printf("%d ", arr[i]);
		i++;
	}
	sort_int_tab(arr, size);
	printf("\nAfter sorting: ");
	i = 0;
	while (i < size) 
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	return (0);
}

void	ft_swap(int *a, int *b) 
{
    int temp; 

    temp = *a; 
    *a = *b;
    *b = temp;
}