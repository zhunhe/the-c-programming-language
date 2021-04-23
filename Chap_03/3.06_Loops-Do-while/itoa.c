#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
** Exercise 3-4.
** In a two's complement number representation,
** our version of itoa does not handle the largest negative number,
** that is, the value of n equal to -(2^wordsize-1).
** Explain why not. Modify it to print that value correctly,
** regardless of the machine on which it runs.
** 
** Answer) Because INT_MIN's two's complement is INT_MIN
** 10000.....00000(INT_MIN) 's one's complement is 01111.....11111
** 01111.....11111 plus one is 10000.....00000
** The way to handle INT_MIN is casting it to a larger data type such as long long int.
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

void	itoa(char *s, int n)
{
	int idx = 0;
	int sign = n < 0 ? -1 : 1;
	long long n_tmp = (long long)n;
	
	n_tmp = n_tmp < 0 ? -n_tmp : n_tmp;
	idx = 0;
	do {
		s[idx++] = n_tmp % 10 + '0';
	} while ((n_tmp /= 10) > 0);
	s[idx++] = sign < 0 ? '-' : '\0';
	s[idx] = '\0';
	reverse(s);
}

int	main(void)
{
	char s[1000];
	itoa(s, INT_MIN);
	printf("%s\n", s);
	return (0);
}
