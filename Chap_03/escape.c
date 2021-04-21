#include <stdio.h>

/*
** Exercise 3-2.
** Write a function escape(s,t)
** that converts like newline and tab into visible escape sequences like \n and \t
** as it copies the string t to s. Use a switch.
** Write a function for the other direction as well,
** converting escape sequences into real characters.
*/

void	escape(char *src, char *dst)
{
	int idx = 0;

	while (*src)
	{
		if (*src > 126 || *src < 32) // not printable char
			continue;
		switch (*src)
		{
			case '\a': case '\b': case '\t':
			case '\n': case '\v': case '\f':
			case '\r': case '\"': case '\'':
			case '\?': case '\\':
				dst[idx++] = '\\';
				/* no break */
				switch (*src)
				{
					case '\a': dst[idx] = 'a'; break;
					case '\b': dst[idx] = 'b'; break;
					case '\t': dst[idx] = 't'; break;
					case '\n': dst[idx] = 'n'; break;
					case '\v': dst[idx] = 'v'; break;
					case '\f': dst[idx] = 'f'; break;
					case '\r': dst[idx] = 'r'; break;
					case '\"': dst[idx] = '\"'; break;
					case '\'': dst[idx] = '\''; break;
					case '\?': dst[idx] = '\?'; break;
					case '\\': dst[idx] = '\\'; break;
				}
				break;
			default:
				dst[idx] = *src;
				break;
		}
		++src;
		++idx;
	}
}

int	main(void)
{
	char src[100] = {'\a', '\b', 'c', '\n', '\r', '\v', '\t', 0};
	char dst[100] = {0};
	int idx = 0;

	escape(src, dst);
	while (dst[idx])
	{
		printf("%d %c\n", dst[idx], dst[idx]);
		++idx;
	}
	return (0);
}
