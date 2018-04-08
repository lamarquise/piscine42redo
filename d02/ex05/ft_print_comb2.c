#include <unistd.h>
#include <stdio.h>

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

int		ft_print_comb2(void)
{
	int		a;
	int		b;
	int		c;		//to help check with other people that your code is correct

	c = 0;
	a = 0;
	b = 1;
	while (a <= 98)
	{
		while (b <= 99)
		{
			print_func(a, b);
			++b;
			++c;
		}
		++a;
		b = a + 1;
	}
	return c;
}

int		main()
{
	printf("\n%i\n", ft_print_comb2());
	return 0;
}
