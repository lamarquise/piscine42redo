#include <stdio.h>
#include <stdlib.h>

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

int		ft_any(char **tab, int(*f)(char*))
{
	while (*tab)
	{
		if (f(*tab) == 1)
			return (1);
		++tab;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		c;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char*) * argc);						//well on the bright side, this is an opportunity for me to perfect my malloc skills
	while (i < argc - 1)
	{
		c = 0;
		while (argv[i + 1][c])
			++c;
		tab[i] = malloc(sizeof(char) * c + 1);
		c = 0;
		while (argv[i + 1][c])
		{
			tab[i][c] = argv[i + 1][c];
			++c;
		}
		tab[i][c] = '\0';
		++i;
	}
	tab[i] = 0;
	if (argc >= 2)
		printf("%i\n", ft_any(tab, char_check));
	return (0);
}
