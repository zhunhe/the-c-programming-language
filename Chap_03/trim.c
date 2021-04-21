#include <stdio.h>
#include <string.h>

int	trim(char *s)
{
	int idx;

	for (idx = strlen(s) - 1; idx >= 0; --idx)
	{
		if (s[idx] != ' '
		&& s[idx] != '\t'
		&& s[idx] != '\n')
		{
			break;
		}
	}
	s[idx+1] = 0;
	return (idx);
}

int	main(int argc, char **argv)
{
	char s[1000];
	int idx = -1;

	if (argc == 2)
	{
		snprintf(s, sizeof(s), "%s", argv[1]);
		trim(s);
		while (s[++idx])
			printf("%3d %c\n", s[idx], s[idx]);
	}
	return (0);
}
