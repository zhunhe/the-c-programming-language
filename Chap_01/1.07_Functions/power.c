#include <stdio.h>

int	power(int base, int n)
{
	int p = 1;

	for (int i = 1; i <= n; i++)
		p = p * base;
	return (p);
}

int	power_recursive(int base, int n)
{
	if (n < 0)
		return (0);
	if (n == 0 || base == 1)
		return (1);
	return (base * power_recursive(base, n - 1));
}

int	main(void)
{
	for (int i = 0; i < 10; i++)
		printf("power(2, %d): %3d, power(-3, %d): %6d\n"
				, i, power(2, i), i, power(-3, i));
	for (int i = 0; i < 10; i++)
		printf("power_recursive(2, %d): %3d, power_recursive(-3, %d): %6d\n"
				, i, power_recursive(2, i), i, power_recursive(-3, i));
	return (0);
}
