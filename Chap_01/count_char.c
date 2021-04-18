#include <stdio.h>

#ifdef EOF
#undef EOF			// already defined EOF -1 in stdio.h
#define EOF		0	// redefine EOF -1 -> 0
#endif

int	main(void)
{
	long	nc;

	nc = 0;
	printf("EOF: %d", EOF);
	while (getchar() != EOF)
		++nc;
	printf("nc: %ld\n", nc);
	return (0);
}
