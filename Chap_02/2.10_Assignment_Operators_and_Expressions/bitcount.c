#include <stdio.h>
#include <stdlib.h>

/*
** Exercise 2-9.
** In a two's complement number system,
** x &= (x-1) delete the rightmost 1-bit in x. Explain why.
** Use this observation to write a faster version of bitcount.
*/

int	bitcount(unsigned x)
{
	int cnt_bits = 0;
	unsigned div = 1;

	while (x)
	{
		++cnt_bits;
		x &= (x - div);
		div <<= 1;
	}
	return (cnt_bits);
}

int	main(int argc, char **argv)
{
	unsigned x;

	if (argc == 2)
	{
		x = (unsigned)atol(argv[1]);
		printf("%d\n", bitcount(x));
	}
	return (0);
}
