#include <stdio.h>

#define MAXLINE		1000

int	count_line(char *s, int maxline);
void	ft_strcpy(char *to, char *from);

int	main(void)
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = count_line(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			ft_strcpy(longest, line);
		}
	}
	printf("%s", longest);
	return (0);
}

int	count_line(char *s, int maxline)
{
	int i;
	char c;

	i = 0;
	while (EOF != (c = getchar()))
	{
		if ((i >= maxline - 1)
		|| (c == '\n'))
			break;
		s[i++] = c;
	}
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return (i);
}

void	ft_strcpy(char *to, char *from)
{
	while ('\0' != (*(to++) = *(from++)))
		;
}
