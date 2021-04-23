#include <stdio.h>
#include <unistd.h>

/*
** Exercise 2-10.
** Write the function lower,
** which converts upper case letters to lower cases,
** with a conditional expression instead of if-else.
*/

void	print_to_lowercase(char *s)
{
	char c;

	while (*s)
	{
		c = (*s >= 'A' && *s <= 'Z' ? *s - 'A' + 'a': *s);
		write(1, &c, 1);
		s++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		while (*argv)
			print_to_lowercase(*(argv++));
	}
	return (0);
}
