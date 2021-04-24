#define SWAP(t, x, y) do \
{ \
	t tmp = x; \
	x = y; \
	y = tmp; \
} while (0)

#include <stdio.h>

int	main(void)
{
	int a = 3;
	int b = 5;
	printf("before a: %d, b: %d\n", a, b);
	SWAP(int, a, b);
	printf("after a: %d, b: %d\n", a, b);
	return (0);
}
