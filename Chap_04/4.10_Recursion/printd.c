#include <stdio.h>

typedef long long	ll;

/* printd: print n in decimal */
void	printd(int n)
{
	ll n_tmp = n;

	if (n_tmp < 0)
	{
		putchar('-');
		n_tmp = -n_tmp;
	}
	if (n_tmp / 10)
		printd(n_tmp / 10);
	putchar(n_tmp % 10 + '0');
}

#include <limits.h>
int	main(void)
{
	printd(INT_MAX);
	printf("\n");
	printd(0);
	printf("\n");
	printd(INT_MIN);
	printf("\n");
	return (0);
}
