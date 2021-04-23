#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define ERROR		-1

int	atoi(char *s)
{
	int idx = 0;
	int sign = 1;
	long long value = 0;

	while (isspace(s[idx]))		// skip white space
		++idx;
	sign = (s[idx] == '-') ? -1 : 1;
	if (s[idx] == '+' || s[idx] == '-')	// skip sign
		++idx;
	for (value = 0; isdigit(s[idx]); ++idx)	// calculate value without sign
		value = value * 10 + (s[idx] - '0');
	if (value * sign > INT_MAX || value * sign < INT_MIN)
	{
		if (value * sign > INT_MAX)
			printf("OVERFLOW!!\n");
		else
			printf("UNDERFLOW!!\n");
		return (ERROR);
	}
	return ((int)value * sign);
}

int	main(int argc, char **argv)
{
	int result;

	if (argc == 2)
	{
		if (-1 == atoi(argv[1]))
			printf("%d\n", -1);
		else if (ERROR != (result = atoi(argv[1])))
			printf("%d\n", atoi(argv[1]));
	}
	else
		printf("atoi(INT_MIN): %d\n", atoi("-2147483648"));
	return (0);
}
