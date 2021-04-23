#include <unistd.h>
#include <stdlib.h>

/*
** Exercise 2-8.
** Write a function rightrot(x,n)
** that returns ther value of the integer x
** rotated to the right by n bit positions.
*/

unsigned	rightrot(unsigned x, int n)
{
	return (x >> n | (~(~0 << n) & x) << (n + 1));
}

void	print_bits(unsigned x)
{
	unsigned div = 1;

	while (div <= x / 2)
		div <<= 1;
	while (div > 0)
	{
		if (x & div)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		div >>= 1;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	unsigned x;
	int n;

	if (argc == 3)
	{
		x = (unsigned)atol(argv[1]);
		n = atoi(argv[2]);
		print_bits(x);
		x = rightrot(x, n);
		print_bits(x);
	}
	return (0);
}
