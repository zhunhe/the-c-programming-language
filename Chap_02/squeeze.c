#include <stdio.h>
#include <stdlib.h>

int	ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int len = 0;

	while (*(s++))
		++len;
	return (len);
}

char	*squeeze(char *s1, char *s2)
{
	char *ret;
	int len;
	int idx = 0;

	if (!*s2)
		return (0);
	len = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (*s2)
	{
		if (!ft_strchr(s1, *s2))
			ret[idx++] = *s2;
		s2++;
	}
	ret[idx] = 0;
	return (ret);
}

int	main(int argc, char **argv)
{
	char *s1;
	char *s2;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		s2 = squeeze(s1, s2);
		if (*s2)
			free(s2);
	}
	return (0);
}
