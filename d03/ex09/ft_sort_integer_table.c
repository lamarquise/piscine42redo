#include <stdio.h>
#include <stdlib.h>

void	ft_sort_integer_table(int *tab, int size)		//Time to BUBBLE SORT!!!!!!!!
{
	int		i;
	int		c;

	i = 0;
	while (i < size - 1)
	{
		while (tab[i] > tab[i + 1])		//while or if??? was an if, needs to be a while or doesnt re-read values after they've been sorted
		{
			c = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = c;
			if (i != 0)
				--i;
		}
		++i;
	}
}

int		main(int argc, char *argv[])
{
	int		tab[argc - 1];
	int		i;

	i = 0;
	if (argc == 1)
		return (0);
	while (i <= argc - 2)
	{
		tab[i] = atoi(argv[i + 1]);
		++i;
	}
	i = 0;
	while (i <= argc - 2)
	{
		printf("%i ", tab[i]);
		++i;
	}
	printf("\n");
	ft_sort_integer_table(tab, argc - 1);			//it's an array so don't need & before tab to send the address
	i = 0;
	while (i <= argc - 2)
	{
		printf("%i ", tab[i]);
		++i;
	}
	return (0);
}
