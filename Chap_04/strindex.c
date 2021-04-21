#include <stdio.h>
#define MAXLINE		1000
#define PATTERN		"ould"

int ft_getline(char *line, int max);
int strindex(char *src, char *searchfor);

int	main(void)
{
	char line[MAXLINE];
	int found = 0;

	while (ft_getline(line, MAXLINE) > 0)
	{
		if (strindex(line, PATTERN) >= 0)
		{
			printf("%s", line);
			found++;
		}
	}
	return (found);
}

int ft_getline(char *line, int max)
{
	int c, i;

	i = 0;
	while (--max > 0
		&& EOF != (c=getchar())
		&& c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return (i);
}

int strindex(char *src, char *searchfor)
{
	int i, j, k;

	for (i = 0; src[i] != '\0'; i++)
	{
		for (j = i, k = 0
			; searchfor[k] != '\0' && src[j] == searchfor[k]
			; j++, k++)
			;
		if (k > 0 && searchfor[k] == '\0')
			return (i);
	}
	return (-1);
}
