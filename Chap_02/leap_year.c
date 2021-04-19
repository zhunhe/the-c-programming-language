#include <stdio.h>

int	ft_atoi(char *s)
{
	int	value = 0;

	if (!*s)
		return (-1);
	while (*s >= '0' && *s <= '9')
		value = value * 10 + (*(s++) - '0');
	return (value);
}

int	main(int argc, char **argv)
{
	int year;

	if (argc == 2)
	{
		year = ft_atoi(argv[1]);
		if (year > 0)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				printf("%d is a leap year\n", year);
			else
				printf("%d is not a leap year\n", year);
		}
	}
	return (0);
}
