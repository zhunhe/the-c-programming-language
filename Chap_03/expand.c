#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	LEN		10000

/*
** Exercise 3-3.
** Write a function expand(s1,s2)
** that expands shorthand notations like a-z in the string
** s1 into the equivalent complete list abc...xyz in s2.
** Allow for letters of either case and digits,
** and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
** Arrange that a leading or trailing - is taken literally.
*/

void	set_data(char *start, char *end, char *src, int idx)
{
	if (!*start)
		*start = src[idx];
	else if (!*end)
		*end = src[idx];
}

void	reset_data(char *start, char *end, char *src, int idx)
{
	if (src[idx + 1] == '-')
		*start = *end;
	else
		*start = 0;
	*end = 0;
}

int	isvalid(char c)
{
	return ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'));
}

void	expand(char *src, char *dst)
{
	char start = 0;
	char end = 0;
	int idx = 0;

	while (src[idx])
	{
		if (isvalid(src[idx]))
		{
			set_data(&start, &end, src, idx);
			if (start < end)
			{
				while (start <= end)
					*(dst++) = start++;
				reset_data(&start, &end, src, idx);
			}
		}
		idx++;
	}
	*dst = 0;
}

int	main(int argc, char **argv)
{
	char s1[LEN];
	char s2[LEN];

	if (argc == 2)
		snprintf(s1, sizeof(s1), "%s", argv[1]);
	else
		snprintf(s1, sizeof(s1), "a-z0-9");
	expand(s1, s2);
	printf("s1: %s, s2: %s\n", s1, s2);
	return (0);
}
