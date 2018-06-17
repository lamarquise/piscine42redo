#include "ft_stock_par.h"
		
		//this version of Split_whitespaces exists in a purely funcontional form for the purposes of the exercise, see d07 for a better version with useful notes
		
int		word_count(char *str)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (!IS_WSPACE(str[i]) && IS_WSPACE(str[i + 1]))
			++n;
		++i;
	}
	return (n);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		n;
	int		i;
	int		s;
	int		c;
	
	tab = malloc(sizeof(char*) * (word_count(str) + 1));
	n = 0;
	c = 0;
	while (str[c])
	{
		s = 0;
		while (IS_WSPACE(str[c]) && str[c])
			++c;
		while (!IS_WSPACE(str[c]) && str[c])
		{
			++s;
			++c;
		}
		tab[n] = malloc(sizeof(char) * (s + 1));
		c = c - s;
		i = 0;
		while (!IS_WSPACE(str[c]))
			tab[n][i++] = str[c++];
		tab[n][i] = '\0';
		++n;
	}
	tab[n] = 0;
	return (tab);
}
