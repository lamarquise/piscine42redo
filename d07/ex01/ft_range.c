#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;
	
	i = 0;
	if (min < max)
	{
		tab = (int*)malloc(sizeof(*tab) * (max - min + 1));
		while (i < max - min)
		{
			tab[i] = min + i;
	//		printf("%i ", tab[i]);								Strangely had trouble printing in the main so if you want to check, that's what this line is for.
			++i;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%i, %i\n", atoi(argv[1]), atoi(argv[2]));
		ft_range(atoi(argv[1]), atoi(argv[2]));
	}
	return (0);
}
