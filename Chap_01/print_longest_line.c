#include <stdio.h>
#include <stdlib.h>

#define MAXLINE		1000

int	count_line(char *s, int maxline);
void	ft_strcpy(char *to, char *from);
char	*reverse(char *s);

int	main(void)
{
	int idx = 0;
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	char *reversed;

	max = 0;
	while ((len = count_line(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			ft_strcpy(longest, line);
		}
//		print all string and length
		printf("string_len: %d, string: %s\n", len, line);
//		print reversed string
		reversed = reverse(line);
		printf("reversed string: %s\n", reversed);
		free(reversed);
	}
	printf("longest string: %s\n", longest);
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
	s[i] = '\0';
	return (i);
}

void	ft_strcpy(char *to, char *from)
{
	while ('\0' != (*(to++) = *(from++)))
		;
}

char	*reverse(char *s)
{
	char *reversed_s;
	int len = 0;
	int idx = 0;

	while (s[len])
		len++;
	reversed_s = (char *)malloc(sizeof(char) * (len + 1));
	while (s[idx] != '\0')
	{
		reversed_s[len - 1 - idx] = s[idx];
		idx++;
	}
	reversed_s[len] = '\0';
	return (reversed_s);
}
