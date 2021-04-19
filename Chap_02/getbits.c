#include <stdio.h>

/*
** getbits: get n bits from position p
** ex) x: 32 p:5 n:3
** get 3 bits from MSB for 32
*/

unsigned getbits(unsigned x, int p, int n)
{
	return ((x >> (p + 1 - n)) & ~(~0 << n));
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
	unsigned x;
	int p, n;
	if (argc == 4)
	{
		x = ft_atou(argv[1]);
		p = (int)ft_atou(argv[2]);
		n = (int)ft_atou(argv[3]);
		printf("x: %u, p: %d, n: %d\n", x, p, n);
		printf("%u\n", getbits(x,p,n));
	}
	return (0);
}
