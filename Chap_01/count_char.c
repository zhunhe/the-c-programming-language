#include <stdio.h>

#define CHAR_FIND		'\t'

int	main(void)
{
	char	c;
	int		cnt = 0;
	
	while (EOF != (c = getchar()))
	{
		if (c == CHAR_FIND)
			++cnt;
	}
	printf("cnt: %d\n", cnt);
	return (0);
}
