#include "sort.h"
#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return (*s2 - *s1);
}

int		count(char **tab)										//not sure how i could do away with this function... hummm... I guess in sort could do that weird thing
{																//where use an if instead of while and reset i to 0 each time, but like eww.
	int		i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

void	ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *))
{
	int		i;
	char	*s;

	i = 0;
	while (i < count(tab) - 1)
	{
		while (cmp(tab[i], tab[i + 1]) < 0)
		{
			s = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = s;
			if (i > 0)
				--i;
		}
		++i;
	}
	while (*tab)												//this part is just here to print so can test.
		printf("%s\n", *tab++);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_advanced_sort_wordtab(ft_split_whitespaces(argv[1]), ft_strcmp);
	return (0);
}
