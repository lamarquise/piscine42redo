#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	i = 0;
	if (min < max)
	{
		*range = (int*)malloc(sizeof(int) * (max - min));
		while (i < max - min)
		{
			(*range)[i] = min + i;		//nothing works if don't have the ()
			++i;
		}
		(*range)[i] = '\0';				//apparently shouldn't end a int array with \0 since its basically just a 0 interpreted as a character, so if there are any other 0s
		return (i);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		*range;

	i = 0;
	if (argc == 3)
	{
		printf("%i, %i\n", atoi(argv[1]), atoi(argv[2]));
		printf("%i\n", ft_ultimate_range(&range, atoi(argv[1]), atoi(argv[2])));
		while (i < atoi(argv[2]) - atoi(argv[1]))
		{
			printf("%d ", range[i]);
			++i;
		}
	}
	return (0);
}
