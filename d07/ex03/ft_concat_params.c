#include <stdlib.h>
#include <stdio.h>

		//well this looks much cleaner

int		count(char **argv)
{
	int		i;
	int		d;
	int		c;

	i = 0;
	d = 1;
	while (argv[d])
	{
		c = 0;
		while (argv[d][c++])
			++i;
		++d;
	}
	return (i + d - 1);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		c;
	int		d;
	char	*tab;

	i = count(argv);
//	printf("%i\n", i);					//use this and | cat -e to count all char to make sure all good
	tab = malloc(sizeof(char) * i);
	d = 1;
	i = 0;
	while (d < argc)					//argv[d])
	{
		c = 0;
		while (argv[d][c])
			tab[i++] = argv[d][c++];
		if (d < argc - 1)
			tab[i++] = '\n';
		++d;							//had a ++i, but put it in the tab[i++] above and tab[++i] below.
	}
	tab[++i] = '\0';
	return (tab);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		printf("%s\n", ft_concat_params(argc, argv));
	return (0);
}
