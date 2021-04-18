#include <stdio.h>

int	power(int base, int n)
{
	int p = 1;

	for (int i = 1; i <= n; i++)
		p = p * base;
	return (p);
}

int	main(void)
{
	for (int i = 0; i < 10; i++)
		printf("power(2, %d): %3d, power(-3, %d): %6d\n", i, power(2, i), i, power(-3, i));
	return (0);
}
