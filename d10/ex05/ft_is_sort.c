#include "d10.h"

		//well i guess i only used the seperate main i made for this program, but whatever, good practice

int		ft_sort_check(int n1, int n2)
{
	return (n2 - n1);
}

int		ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int		i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		++i;
	}
	return (1);
}
