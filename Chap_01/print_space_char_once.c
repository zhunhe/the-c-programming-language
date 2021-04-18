#include <stdio.h>

#define SPACE_CHAR		' '

int	main(void)
{
	char	c;
	char	c_before = 0;
	int		print_space = 1;
	
	while (EOF != (c = getchar()))
	{
		// If a space has already been printed,
		// the spaces following the next are not printed
		if (c_before == SPACE_CHAR)
		{
			while (SPACE_CHAR == (c = getchar()))
				;
		}
		putchar(c);
		c_before = c;
	}
	return (0);
}
