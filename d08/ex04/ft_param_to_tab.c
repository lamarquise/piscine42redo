#include "proto.h"
#include "ft_stock_par.h"

		//OK WTF is split_whitespaces used for??? i could just rewrite it better for this, ft_split would be more usefull! uhg...

void	ft_show_tab(struct s_stock_par *par);
char	**ft_split_whitespaces(char *str);

int		count(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*fill(char *av, char *copy, int size)
{
	int		i;
	
	i = 0;
	copy = malloc(size + 1);
	while (copy[i])
	{
		copy[i] = av[i];
		++i;
	}
	copy[i] = '\0';
	return (copy);			//or don't return depending on the way you set it up.
}

struct s_stock_par *ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*par;
	int		n;

	n = 0;
	par = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	while (n < ac)			//or something else
	{												//shit i still need to allocate everything
		par[n].size_param = count(av[n]);
		par[n].str = av[n];		//not &av[n] aparently
		par[n].copy = fill(av[n], par[n].copy, count(av[n]));		//or don't have a return and just have it change the pointer, maybe, then would get rid of =, just have ft
		par[n].tab = ft_split_whitespaces(av[n]);
		++n;
	}
	par[n].str = '\0';
	return (par);		//i guess??? Eventually will be useful
}

int		main(int ac, char **av)
{
	ft_show_tab(ft_param_to_tab(ac, av));
	return (0);
}
