#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_func(int a, int b)
{
	ft_putchar(a / 10 + 48);
	ft_putchar(a % 10 + 48);
	ft_putchar(' ');
	ft_putchar(b / 10 + 48);
	ft_putchar(b % 10 + 48);

	if (a != 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (a <= 98)
	{
		while (b <= 99)
		{
			print_func(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}

void	main(void)
{
	ft_print_comb2();
}
