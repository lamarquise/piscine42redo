#include <stdio.h>

int		char_check(char *str)
{
	while (*str)
	{
		if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
			return (1);
		++str;
	}
	return (0);
}

int		ft_count_if(char **tab, int(*f)(char*))
{
	int		i;

	i = 0;
	while (*tab)
	{
		i = i + f(*tab);
		++tab;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		printf("%i\n", ft_count_if(argv, &char_check));
	return (0);
}
