#include <stdio.h>
#include <stdlib.h>

int	bitcount(unsigned x)
{
	int num_of_1 = 0;

	while (x)
	{
		if (x & 1)
			++num_of_1;
		x >>= 1;
	}
	return (num_of_1);
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
