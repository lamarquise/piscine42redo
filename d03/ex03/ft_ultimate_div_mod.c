#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *a / *b;
	*b = c % *b;
}

int		main()
{
	int		a;
	int		b;

	a = 144;
	b = 12;
	ft_ultimate_div_mod(&a, &b);
	printf("%i\n%i\n", a, b);		//you can't put the function int the printf because it has no return, it's void, otherwise could
	return (0);
}
