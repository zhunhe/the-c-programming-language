#include <unistd.h>
#include <stdio.h>

/*
** Exercise 2-7.
** Write a function invert(x,p,n)
** that returns x with the n bits that begin at position p inverted
** (i.e., 1 changed into 0 and vice versa), leaving the other unchanged.
*/

unsigned	invert(unsigned x, int p, int n)
{
	unsigned ret = x;
	unsigned xor = 1;
	
	for (int idx = 0; idx < n; ++idx)
	{
		if ((1 << (p - idx)) & ret)
			ret = ret & ~(1 << (p - idx));
		else
			ret = ret | (1 << (p - idx));
	}
	return (ret);
}

unsigned	atou(char *s)
{
	unsigned value = 0;

	if (!*s)
		return (0);
	while (*s)
		value = value * 10 + *(s++) - '0';
	return (value);
}

void	print_bits(unsigned n)
{
	unsigned div = 1;

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
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	unsigned x;
	int p, n;

	if (argc == 4)
	{
		x = atou(argv[1]);
		p = (int)atou(argv[2]);
		n = (int)atou(argv[3]);
		print_bits(x);
		x = invert(x, p, n);
		print_bits(x);
	}
	return (0);
}
