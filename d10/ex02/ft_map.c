#include <stdlib.h>
#include <stdio.h>


int		ft_is_positive(int i)
{
	if (i >= 0)
		return (1);
	return (0);
}

int		*ft_map(int *tab, int length, int(*f)(int))
{
	int		i;
	int		*arr;								//apparently i need this, i mean, it prolly wouldn't have been great to change the OG table, but still i thought i might
												//just do it anyway, cuz fuck it, but nvm
	i = 0;										
	arr = malloc(sizeof(int) * length);
	while (i < length)
		arr[i++] = f(*tab++);					//kinda cool this works
	return (arr);
}

int		main(int argc, char **argv)
{
	int		*tab;
	int		i;

	if (argc >= 2)
	{
		i = 0;
		tab = malloc(sizeof(int) * argc - 1);
		while (i < argc - 1)
		{
			tab[i] = atoi(argv[i + 1]);
			++i;
		}
		i = 0;
		while (i < argc - 1)
			printf("%d\n", *(ft_map(tab, argc - 1, &ft_is_positive) + i++));			//also, WTF, this works, what???
	}
	return (0);
}
