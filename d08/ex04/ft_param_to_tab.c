#include "ft_stock_par.h"

int		count(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*fill(char *av, int size)
{
	int		i;
	char	*copy;
	
	i = 0;
	copy = malloc(size + 1);
	while (i < size)
	{
		copy[i] = av[i];
		++i;
	}
	copy[i] = '\0';
	return (copy);
}

struct s_stock_par *ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*par;
	int		n;

	n = 0;
	par = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	while (n < ac)
	{
		par[n].size_param = count(av[n]);
		par[n].str = av[n];		//not &av[n] aparently
		par[n].copy = fill(av[n], count(av[n]));
		par[n].tab = ft_split_whitespaces(av[n]);
		++n;
	}
	par[n].str = '\0';
	return (par);
}

int		main(int ac, char **av)
{
	ft_show_tab(ft_param_to_tab(ac, av));
	return (0);
}
