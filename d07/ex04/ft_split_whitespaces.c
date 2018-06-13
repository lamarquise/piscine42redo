#include <stdlib.h>
#include <stdio.h>

#define	IS_WSPACE(x) (((x) >= 9 && (x) <= 13) || (x) == 32 || (x) == 0)
		//This sort if define is forbiden by the norm at 42, but im ol with it here for now.

			//OK so once again, i basically did it Pascal's way, but i changed a few things that i didn't get from his version, will need to ask questions, like seriously!

int		word_count(char *str)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (str[i])								//ok so this is working pretty well
	{
		if (!IS_WSPACE(str[i]) && IS_WSPACE(str[i + 1]))
			++n;
		++i;
	}
	return (n);
}
/*		we suspend this because instead allocate memory each time it's needed, easier now that we have IS_WSPACE
int		*mem_calc(char *str, int n)
{
	int		*numtab;							//not + 1 because tab so starts at 0, cool
	int		i;
	int		c;

	c = 0;
//	n = 0;
	numtab = malloc(sizeof(int) * n);
	n = 0;
	while (str[c])								//may need some tweaking but the concept is there
	{
		i = 0;
		while (!IS_WSPACE(str[c]))
		{
			++i;
			++c;
		}
		if (i > 0)
			numtab[n++] = i + 1;				//here add i + 1 if it turns out each word that has been slpit needs to be terminated by \0
		++c;
	}
	numtab[n] = 1;
	return (numtab);
}	*/
/*			we can also suspend this for similar reasons.
void	fill_ft(char *str, char **tab)			//could add n as an input for securety and safeguarding things but whatever
{
	int		c;
	int		i;
	int		d;

	c = 0;
	i = 0;
	while (str[c])								//removed [c]s, it got weird
	{
		d = 0;
		while (!IS_WSPACE(str[c]))
		{
			tab[i][d++] = str[c++];
	//		++d;
	//		++c;
		}
		tab[i][d] = '\0';
		if (!IS_WSPACE(str[c]) && IS_WSPACE(str[c + 1]))
			++i;
		++c;
//		++str;									//don't entirely understand why *str++ didn't work, or what this is, but...
	}
//	tab[i] = 0;									//ok so just this litterally wreked some shit.
}	*/

char	**ft_split_whitespaces(char *str)
//void	ft_split_whitespaces(char *str)
{
//	int		*numtab;							//the array that contains the amount of mem to be allocated for each word, in order
	char	**tab;								//where i put the words that have been sniped, but wait 2 *s??? not sure
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
/*
	i = 0;
	n = word_count(str);						//could put this line in the calling of other functions, as needed... kinda cool
	printf("%i\n", n);
	numtab = mem_calc(str, n);
	while (i < n)
		printf("%d ", numtab[i++]);
	printf("\n");
	i = 0;
	tab = malloc(sizeof(char*) * n + 1);		//I am hesitant to believe that this is good, but doesnt compile without this line
	while (i <= n)								//<= i think, for the 0 at the end
	{
		tab[i] = malloc(numtab[i]);				//removed sizeof(char)
		++i;
	}
	fill_ft(str, tab);
	return (tab);		*/
}

int		main(int argc, char *argv[])
{
	char	**tab;
	int		c;

	if (argc == 2)
	{
		tab = ft_split_whitespaces(argv[1]);
		c = 0;
		while (tab[c])							//ok whether it be **tab, *tab[c] or tab[c], same thing happens, a bunch of numbers get printed
		{
			printf(("%s\n"), tab[c]);
			++c;
		}
	}
	return (0);
}
