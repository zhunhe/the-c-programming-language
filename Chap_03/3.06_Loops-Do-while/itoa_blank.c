#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
** Exercise 3-6.
** Write a version of itoa that accepts three arguments instead of two.
** The third argument is a minimum field width;
** the converted number must be padded with blanks on the left
** if necessary to make it wide enough.
*/
void	reverse(char *s)
{
	char tmp;
	int j = strlen(s) - 1;
	for (int i = 0; i < j; i++, j--)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

void	itoa(char *s, int n, int len)
{
	int idx = 0;
	int sign = n < 0 ? -1 : 1;
	long long n_tmp = (long long)n;
	
	n_tmp = n_tmp < 0 ? -n_tmp : n_tmp;
	idx = 0;
	do {
		s[idx++] = n_tmp % 10 + '0';
	} while ((n_tmp /= 10) > 0);
	if (sign < 0)
		s[idx++] = '-';
	while (idx < len - 1)
		s[idx++] = ' ';
	s[idx] = '\0';
	reverse(s);
}

int	main(void)
{
	int idx = 0;
	char s[1000];
	itoa(s, INT_MIN, 20);
	printf("%s\n", s);
	return (0);
}
