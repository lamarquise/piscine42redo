#ifndef __FT_STOCK_PAR_H__

	#define __FT_STOCK_PAR_H__
	#include <unistd.h>
	#include <stdlib.h>

	typedef struct s_stock_par
	{
		int size_param;
		char *str;
		char *copy;
		char **tab;
	}				t_stock_par;

#endif

void	ft_show_tab(struct s_stock_par *par);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);		//i think this will be useful for ex05, i think...
char	**ft_split_whitespaces(char *str);

