#include <stdio.h>

void	tab_to_space(int num);

int	main(void)
{
	char c;
	int wd_len = 0;

	while (EOF != (c = getchar()))
	{
		if (c == '\t')
		{
			tab_to_space(8 - wd_len == 0 ? 8 : 8 - wd_len);
			wd_len = 0;
		}
		else
		{
			putchar(c);
			wd_len++;
		}
	}
	return (0);
}

void	tab_to_space(int num)
{
	for (int i = 0; i < num; i++)
		putchar(' ');
}
