#include "ft_stock_par.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_par *par)		//well it's a tad long, but should be good.
{
	int		n;
	int		i;
	int		c;

	n = 0;
	while (par[n])
	{
		i = 0;
		while (par[n].copy[i])
		{
			ft_putchar(par[n].copy[i])
			++i;
		}
		ft_putchar('\n');
		ft_putchar(par[n].size_param);
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
