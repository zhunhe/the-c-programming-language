#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void	print_bits(unsigned int n)
{
	unsigned int div = 1;

	while (div <= n / 2)
		div = div << 1;
	while (div > 0)
	{
		if (n & div)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		div = div >> 1;
	}
}

unsigned int	ft_atou(char *s)
{
	unsigned int value = 0;
	while (*s)
		value = value * 10 + *(s++) - '0';
	return (value);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_bits(ft_atou(argv[1]));
	else
		print_bits(UINT_MAX);
	return (0);
}
