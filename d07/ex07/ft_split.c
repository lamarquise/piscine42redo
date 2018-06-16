#include <stdio.h>
#include <stdlib.h>

		//Works pertty good, not quite within the norm, but that's not too bad, But still need to ask Pascal some Q's

int		set_test(char s, char *charset)											//basically answers, does s belong to charset
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == s)
			return (1);
		++i;
	}
	return (0);
}

int		word_counter(char *str, char *charset)
{
	int		n;
	int		c;

	n = 0;
	c = 0;
	while (str[c])																//for some reason when i had *str, it segfaults, how did pascal do it?
	{
		if (set_test(str[c], charset) == 0 && (set_test(str[c + 1], charset) == 1 || str[c + 1] == '\0'))
			++n;
		++c;
	}
	return (n);
}

char	**ft_split(char *str, char *charset)									//we are bloody close to being within the 25 line limit, not bad
{
	char	**tab;
	int		len;
	int		n;
	int		c;
	int		i;																	//i cuz ideally i would get rid of this variable

	c = 0;
	n = 0;
	tab = malloc(sizeof(char*) * (word_counter(str, charset) + 1));
	while (str[c])																//perhaps it is worth asking pascal about his weird notations now.
	{
		while (set_test(str[c], charset) == 1 && str[c])
			++c;
		len = 0;
		while (set_test(str[c + len], charset) == 0 && str[c + len] != '\0')	//could compulsively reallocate tab[n] in the while, to save a line?
			++len;																//that's way more clever, oh shit is that what pascal's weird syntax does???
		tab[n] = malloc(sizeof(char) * (len + 1));
		i = 0;
		while (set_test(str[c], charset) == 0 && str[c])						//still don't know why when i used i <= len it would segfault for < , len -1, len +1, ???
			tab[n][i++] = str[c++];
		tab[n][i] = '\0';
		++n;
	}
	tab[n] = 0;
	return (tab);
}

int		main(int argc, char **argv)
{
	char	**tab;
	int		c;

	c = 0;
	if (argc == 3)
	{
		tab = ft_split(argv[1], argv[2]);
		while (tab[c])
			printf("%s\n", tab[c++]);
	}	
	return (0);
}
