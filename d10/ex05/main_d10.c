#include "d10.h"

		//yea not too shabby for a generic main.

int		main(int argc, char **argv)
{
	int		i;
//	int		c;
//	char	**tab;
	int		*tab;

	if (argc > 1)
	{
		i = 0;
		tab = malloc(sizeof(char*) * argc - 1);
		while (i < argc - 1)
		{

			tab[i] = atoi(argv[i + 1]);
			
			//This is the part you would add  if you needed a table of char strings.

/*			c = 0;
			while (argv[i + 1][c])
				++c;
			tab[i] = malloc(sizeof(char) * c + 1)
			c = 0;
			while (argv[i + 1][c])
			{
				tab[i][c] = argv[i + 1][c];
				++c;
			}
			tab[i][c] = '\0';
*/			++i;
		}
//		tab[i] = 0;

		printf("%i\n", ft_is_sort(tab, argc - 1, ft_sort_check));
	}								//oh shit is there a thing i can do where i just put name of func and use like a declaration or something...
	return (0);						//worth looking into in my next seperate .h and main files
}
