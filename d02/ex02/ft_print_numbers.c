#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	int		a;

	a = '0';
	while (a <= '9')
	{
		ft_putchar(a);
		a++;
	}
}

void	main(void)
{
	ft_print_numbers();
}
