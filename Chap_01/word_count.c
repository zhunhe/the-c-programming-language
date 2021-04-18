#include <stdio.h>

int	is_blank(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	main(void)
{
	char c;
	char c_before = 0;
	int wd_cnt = 0;

	while (EOF != (c = getchar()))
	{
		if ((is_blank(c_before) || c_before == 0)
		&& (!is_blank(c)))
			wd_cnt++;
		c_before = c;
	}
	printf("count of word: %d\n", wd_cnt);
	return (0);
}
