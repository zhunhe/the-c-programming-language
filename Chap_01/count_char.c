#include <stdio.h>

#define TAB_CHAR		'\t'
#define LINEFEED_CHAR		'\n'
#define SPACE_CHAR		' '

int	main(void)
{
	char c;
	int cnt_tab = 0;
	int cnt_ln = 0;
	int cnt_space = 0;
	
	while (EOF != (c = getchar()))
	{
		switch (c)
		{
			case TAB_CHAR: ++cnt_tab; break;
			case LINEFEED_CHAR: ++cnt_ln; break;
			case SPACE_CHAR: ++cnt_space; break;
			default: break;
		}
	}
	printf("TAB: %d, LINDFEED: %d, SPACE: %d\n", cnt_tab, cnt_ln, cnt_space);
	return (0);
}
