#include <stdio.h>
#include <stdlib.h>

unsigned long int next = 1;

int	rand(void)
{
	next = next * 1103515245 + 12345;
	return ((unsigned int)((next/65536) % 32768));
}

void	srand(unsigned int seed)
{
	next = seed;
}

int	main(int argc, char **argv)
{
	int idx = 0;

	if (argc == 2)
		srand((unsigned int)atoi(argv[1]));	// set seed
	while (idx < 10)
	{
		printf("%2dth rand: %u\n", idx + 1, rand());
		idx++;
	}
	return (0);
}
