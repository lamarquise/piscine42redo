#ifndef __FT_STOCK_PAR_H__

	#define __FT_STOCK_PAR_H__
	#include <unistd.h>
	#include <stdlib.h>
	#define IS_WSPACE(x) (((x) >= 9 && (x) <= 13) || (x) == 32 || (x) == 0)

	typedef struct s_stock_par
	{
		int size_param;
		char *str;
		char *copy;
		char **tab;
	}				t_stock_par;

void	ft_show_tab(struct s_stock_par *par);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);
char	**ft_split_whitespaces(char *str);

#endif
