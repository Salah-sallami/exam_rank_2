#include <stdio.h>
#include <stdlib.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = 0;
	while (s2 && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return s1;	
}

char    **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int len = 0;
	char **split;

	// 1 - check str
	if(!str)
	{
		split = (char **)malloc(sizeof(char *));
		split[0] = NULL;
		return (split);
	}

	// 2 - calcul sum words
	while (str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i]) 
			j++;
		while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	split = (char **)malloc((j + 1) * sizeof(char *));


	// 3 - start => len => allocation => ft_strncpy
	i = 0;
	j = 0;
	while (str[i])
	{
		// 3(1) - start 
		while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		// 3(2) - len 
		while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		if (i > j)
		{
			// 3(3) - allocation 
			split[len] = (char *)malloc(sizeof(char *) * ((i - j) + 1));
			// 3(4) - ft_strncpy 
			ft_strncpy(split[len++], &str[j], i - j);
		}
	}
	split[len] = NULL;
	return split;
}

int main()
{
	// char **p = ft_split("dhhs djks       salah eddine    sallami", ' ');
	  char str[] = "   dhhs ";
	char **words = ft_split(str);
			printf("%s\n", words[0]);
			printf("%s\n", words[1]);
			printf("%s\n", words[2]);
			printf("%s\n", words[3]);
			printf("%s\n", words[4]);
			printf("%s\n", words[5]);
			printf("%s\n", words[6]);
			printf("%s\n", words[7]);
	
	// if (words)
	// {
	// 	for (int i = 0; words[i]; i++)
	// 	{
	// 		printf("%s\n", words[i]);
	// 		free(words[i]);
	// 	}
	// 	free(words);
	// }
	return 0;
}