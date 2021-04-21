#include <stdio.h>
#include <string.h>
#include <limits.h>

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
	s[idx] = sign < 0 ? '-' : '\0';
	s[++idx] = '\0';
	reverse(s);
}

int	main(void)
{
	char s[1000];
	itoa(s, INT_MIN);
	printf("%s\n", s);
	return (0);
}
