#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_func(int *tab)
{
	ft_putchar(tab[0] + 48);
	ft_putchar(tab[1] + 48);
	ft_putchar(tab[2] + 48);
	if (tab[0] != 7)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	else
		ft_putchar('\n');
}

void	ft_print_comb(void)
{
	int		number[3];

	number[0] = 0;
	while (number[0] <= 7)
	{
		number[1] = number[0] + 1;
		number[2] = number[0] + 2;
		while (number[1] <= 8)
		{
			while (number[2] <= 9)		//(number[cursor] <= 9 - 2 + cursor)???
			{
				print_func(&number[0]);
				number[2]++;
			}
			number[1]++;
			number[2] = number[1] + 1;
		}
		number[0]++;
	}
}

void	main(void)
{
	ft_print_comb();
}
