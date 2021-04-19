#include <unistd.h>
#include <ctype.h>

void	print_to_lowercase(char *s)
{
	char c;

	while (*s)
	{
		c = tolower(*(s++));
		write(1, &c, 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		while (*argv)
		{
			print_to_lowercase(*(argv++));
			write(1, "\n", 1);
		}
	}
	return (0);
}
