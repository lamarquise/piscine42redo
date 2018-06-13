#include <stdlib.h>
#include <stdio.h>

#define	IS_WSPACE(x) (((x) >= 9 && (x) <= 13) || (x) == 32 || (x) == 0)
		
		//ok so obviously this is the condensed functional and clearer version of split_whitespaces, it however doesn't help answer any questions...

void	ft_print_words_tables(char **tab);

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
		while (!IS_WSPACE(str[c]) && str[c])			//if really feel like it could prolly make this shorter to conform to the norm.
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
		if (n < word_count(str))						//the only useful new line in this whole program, now it's too long...
			++n;
	}
	tab[n] = 0;
	return (tab);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		ft_print_words_tables(ft_split_whitespaces(argv[1]));		//vaguely clever...
	return (0);
}
