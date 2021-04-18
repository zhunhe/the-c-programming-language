#include <stdio.h>

int	main(void)
{
	int	c;
	int	cnt_nl;

	cnt_nl = 0;
	while (EOF != (c = getchar()))
	{
		if (c == '\n')
			++cnt_nl;
	}
	printf("cnt_nl: %d\n", cnt_nl);
	return (0);
}
