#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int		main()
{
	int		a;
	int		b;
	int		div;
	int		mod;

	a = 144;
	b = 12;
	ft_div_mod(a, b, &div, &mod);		//somehow div and mod can be sent despite now being initiallized, be careful could be on an OS by OS basis
	printf("%i\n%i\n", div, mod);
	return (0);
}
