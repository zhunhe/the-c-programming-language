#include <stdio.h>

int	main(void)
{
	int	c;

	printf("EOF: %d\n", EOF);		// EOF: -1
	while (EOF != (c = getchar()))
		putchar(c);
	return (0);
}
