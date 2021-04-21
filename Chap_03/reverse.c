#include <stdio.h>
#include <string.h>

void	swap(char *val1, char *val2)
{
	char temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void	reverse(char *s)
{
	int j = strlen(s) - 1;
	for (int i = 0; i < j; ++i, --j)
		swap(&s[i], &s[j]);
}

int	main(int argc, char **argv)
{
	char *s;

	if (argc == 2)
	{
		s = argv[1];
		printf("%s\n", s);
		reverse(s);
		printf("%s\n", s);
	}
	return (0);
}
