#include <stdio.h>

int	is_blank(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

void	print_char(char c, char c_before)
{
	if ((!is_blank(c_before))
	&& (is_blank(c)))
		putchar('\n');
	else if (!is_blank(c))
		putchar(c);
}

int	main(void)
{
	char c;
	char c_before = 0;
	int wd_cnt = 0;

	while (EOF != (c = getchar()))
	{
		print_char(c, c_before);
		c_before = c;
	}
	return (0);
}
