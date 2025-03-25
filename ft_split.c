#include <stdlib.h>

size_t ft_strlen(const char *s1)
{
	size_t len;

	len = 0;
	while (s1[len])
		len++;
	return (len);
}

char *ft_strdup(const char *s1)
{
	char *p;
	int i;

	p = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *p;
	size_t i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)   // 
		len = ft_strlen(s) - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}


static size_t counts(const char *s)
{
    size_t count = 0;
    int in_word = 0;
	int i = 0;
    while (s[i])
    {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        {
            in_word = 0;  
        }
        else if (in_word == 0)
        {
            in_word = 1; 
            count++;
        }
        i++;
    }
    return count;
}


static char **shorten(char **p, size_t x)
{
	while (x > 0)
		free(p[--x]);
	free(p);
	return (NULL);
}

static char **shoten2(char **p, const char *s)    // "  \t \n hello/0 word/0" NULL
{
	size_t i;
	size_t start;
	size_t x;

	i = 0;
	x = 0;
	while (s[i] && x < counts(s))    // 0 < 2  s = 6  end = 11
	{
		while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
			i++;
		start = i;
		while (s[i] && s[i] != '\t' && s[i] != '\n' && s[i] != ' ')
			i++;
		p[x++] = ft_substr(s, start, i - start);
		if (!p[x - 1])
			return (shorten(p, x));
	}
	p[x] = NULL;
	return (p);
}

char **ft_split(const char *s)
{
	size_t count;
	char **p;

	if (!s)
		return (NULL);
	count = counts(s);
	p = (char **)malloc(sizeof(char *) * (count + 1));
	if (!p)
		return (NULL);
	return (shoten2(p, s));
}
// Test the function
int main()
{
	int i = 0;
	char str[] = " deof efef ";
	// char **words = ft_split(str);
	ft_split(str);

	// while(words[i])
	// {
	// 	printf("%s\n",words[i]);
	// 	i++;
	// }
	return 0;
}
