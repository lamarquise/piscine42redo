#include "ft_stock_par.h"

		//well it's way too long, but it works so... I learned what i came to learn.

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	while (nbr >= 10)
	{
		ft_putchar(nbr % 10 + 48);
		nbr = nbr / 10;
	}
	ft_putchar(nbr + 48);
}

void	ft_show_tab(struct s_stock_par *par)
{
	int		n;
	int		i;
	int		c;

	n = 0;
	while (par[n].str)
	{
		i = 0;
		while (par[n].str[i])				//can use copy or str, same dif.
		{
			ft_putchar(par[n].str[i]);
			++i;
		}
		ft_putchar('\n');
		ft_putnbr(par[n].size_param);
		ft_putchar('\n');
		i = 0;
		while (par[n].tab[i])
		{
			c = 0;
			while (par[n].tab[i][c])
			{
				ft_putchar(par[n].tab[i][c]);
				++c;
			}
			ft_putchar('\n');
			++i;
		}
		++n;
	}
}
