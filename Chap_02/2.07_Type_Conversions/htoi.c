#include <stdio.h>

#define ERROR		-1

int	get_number_if_decimal(char c)
{
	return (c >= '0' && c <= '9' ? c - '0' : ERROR);
}

int	get_number_if_upper(char c)
{
	return (c >= 'A' && c <= 'F' ? c - 'A' + 10 : ERROR);
}

int	get_number_if_lower(char c)
{
	return (c >= 'a' && c <= 'f' ? c - 'a' + 10 : ERROR);
}

char	get_number_if_valid(char c)
{
	char ret = ERROR;

	if (ERROR != (ret = get_number_if_decimal(c)))
		return (ret);
	if (ERROR != (ret = get_number_if_lower(c)))
		return (ret);
	if (ERROR != (ret = get_number_if_upper(c)))
		return (ret);
	return (ret);
}

int	htoi(char *s)
{
	int value = 0;
	int value_tmp = 0;

	if (!*s)
		return (-1);
	while (get_number_if_valid(*s) != ERROR)
		value = value * 16 + get_number_if_valid(*(s++));
	return (value);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n", htoi(argv[1]));
	return (0);
}
