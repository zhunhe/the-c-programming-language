#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
** Exercise 3-5.
** Write the function itob(n,s,b)
** that converts the integer n into a base b character representation in the string s.
** In particular, itob(n,s,16) formats n as a hexadecimal integet in s.
*/
void	reverse(char *s)
{
	char tmp;

	int j = strlen(s) - 1;
	for (int i = 0; i < j; ++i, --j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

void	itob(char *s, int n, int base)
{
	int idx = 0;
	int sign = n < 0 ? -1 : 1;
	char tmp;
	long long n_tmp = (long long)n;
	
	n_tmp = n_tmp < 0 ? -n_tmp : n_tmp;
	idx = 0;
	do {
		tmp = n_tmp % base;
		if (tmp < 10)
			s[idx++] = tmp + '0';
		else
			s[idx++] = tmp + 'A' - 10;
	} while ((n_tmp /= base) > 0);
	s[idx] = sign < 0 ? '-' : '\0';
	s[++idx] = '\0';
	reverse(s);
}

int	main(void)
{
	char s[1000];
	itob(s, INT_MAX, 16);
	printf("%s\n", s);
	itob(s, INT_MIN, 16);
	printf("%s\n", s);
	return (0);
}
