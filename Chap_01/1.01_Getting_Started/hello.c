#include <stdio.h>

int	main(void)
{
#if 1
	printf("hello\n");
	printf("world!\n");
#else
	printf("hello			// compile error
			world!");
#endif
	return (0);
}
