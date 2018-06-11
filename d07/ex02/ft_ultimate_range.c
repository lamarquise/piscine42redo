#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

		//ok so i don't understand why this isnt working, i understand how other one works, but not why mine doesn't...

		//So im happy to use someone else's solution, but what i want, the reason im doing this exercise, is to understand why my way doesn't work...

		//ok so need some work, i think the ft function is fine, but once again my trouble is with the fucking main, like i can't test, uhggg...

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	i = 0;
	if (min < max)
	{
		printf("yo\n");
		*range = (int*)malloc(sizeof(int) * (max - min));
		printf("hi there\n");
		while (i < max - min)			//this seems to be where it segfaults
		{
			printf("sup ");
			*range[i] = min + i;		//tried removing *, didn't compile
			++i;
			printf("bruh \n");
		}
		*range[i] = '\0';
		printf("still here");
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
