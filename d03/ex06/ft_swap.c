#include <stdio.h>

void	ft_swap(int	*a, int	*b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

int		main()
{
	int		a;
	int		b;

	a = 15;
	b = -789525;
	ft_swap(&a, &b);
	printf("%i\n%i\n", a, b);
	return (0);
}
