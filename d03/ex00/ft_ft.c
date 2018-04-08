#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int		main()
{
	int		a;

	a = 21;
	printf("%i\n", a);
	ft_ft(&a);
	printf("%i\n", a);
	return (0);
}
