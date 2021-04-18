#include <stdio.h>

int	is_blank(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	main(void)
{
	int word_len_table[20] = {0, };
	int word_len = 0;
	char c;
	char c_before = 0;

	while (EOF != (c = getchar()))
	{
		if ((!is_blank(c_before) || c_before == 0)
		&& (!is_blank(c)))
			word_len++;
		else if (word_len)
		{
			word_len_table[word_len + 1]++;
			word_len = 0;
		}
		c_before = c;
	}
	for (int idx = 0; idx < 20; idx++)
		printf("table[%d]: %d\n", idx, word_len_table[idx]);
	return (0);
}
