#include <stdio.h>
#include <unistd.h>

/*
** Exercise 2-6
** Write a function setbits(x,p,n,y)
** that returns x with the n bits that begin at position p set to there rightmost n bits of y,
** leaving the other bits unchanged.
*/

unsigned	getbits(unsigned x, int p, int n)
{
	return ((x >> (p + 1 - n)) & ~(~0 << n));
}

unsigned	set_0_bits(unsigned x, int p, int n)
{
	unsigned ret = x;
	unsigned zero_bit = 0;
	
	for (int idx = 0; idx < n; idx++)
		zero_bit = (zero_bit << 1) + 1;
	zero_bit = ~(zero_bit << (p - 1));
	return (ret & zero_bit);
}

unsigned	setbits(unsigned x, int p, int n, int y)
{
	unsigned ret = x;

	// 1. make 0 n bits begin at p of x
	ret = set_0_bits(x, p, n);
	// 2. set n bits of x from rightmost n bits of y
	ret = ret | (getbits(y, n - 1, n) << (p - n + 1));
	return (ret);
}

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
	write(1, "\n", 1);
}

unsigned ft_atou(char *s)
{
	unsigned value = 0;

	while (*s)
		value = value * 10 + *(s++) - '0';
	return (value);
}

int	main(int argc, char **argv)
{
	unsigned int x, p, n, y;
	if (argc == 5)
	{
		x = ft_atou(argv[1]);
		p = ft_atou(argv[2]);
		n = ft_atou(argv[3]);
		y = ft_atou(argv[4]);
		printf("x: %d, p: %d, n:%d, y:%d\n", x, p, n, y);
		print_bits(x);
		x = setbits(x, p, n, y);
		print_bits(x);
	}
	return (0);
}
