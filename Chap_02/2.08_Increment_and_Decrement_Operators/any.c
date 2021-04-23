#include <stdio.h>
#include <limits.h>
#include <string.h>

#define ERROR		-1

int	ft_strchr(char *s, char c)
{
	int idx = 0;

	while (s[idx])
	{
		if (s[idx] == c)
			return (idx);
		idx++;
	}
	return (ERROR);
}

char	*any(char *string, char *charset)
{
	int ret_idx = INT_MAX;
	int idx = 0;
	int find_idx = ERROR;

	while (charset[idx])
	{
		find_idx = ft_strchr(string, charset[idx]);
		if (find_idx != ERROR && find_idx < ret_idx)
			ret_idx = find_idx;
		idx++;
	}
	return (ret_idx != INT_MAX ? &string[ret_idx] : 0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("strpbrk: %s\n", strpbrk(argv[1], argv[2]));
		printf("any: %s\n", any(argv[1], argv[2]));
	}
	return (0);
}
