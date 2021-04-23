#include <stdio.h>

#define MAXLINE		100

int ft_getline(char *line, int max);

/* rudimentary calculator */
int	main(void)
{
	double sum, atof(char[]);
	char line[MAXLINE];
	sum = 0;
	while (ft_getline(line, MAXLINE) > 0)
		printf("\t%lf\n", sum += atof(line));
	return (0);
}

int ft_getline(char *line, int max)
{
	int c, i;

	i = 0;
	while (--max > 0
		&& EOF != (c=getchar())
		&& c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return (i);
}
