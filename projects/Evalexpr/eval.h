#ifndef	__EVAL_H___

	#define	_EVAL_H__

	#include <unistd.h>
	#include <stdlib.h>
	#include <stdio.h>

	#define IS_WSPACE(x) (((x) >= 9 && (x) <= 13) || (x) == 32 || (x) == 0)
	#define ABS(Value) (Value >= 0 ? Value : -Value)

	typedef struct	s_opp
	{
		char *op;
		int	(*f)(int, int);
	}				t_opp;

	int		ft_atoi(char *str);
	void	ft_putnbr(int nb);
	void	ft_putchar(char c);
	char	**ft_split_whitespaces(char *str);
	int		ft_strcmp(char *s1, char *s2);
	int		ft_strlen(char *str);
	void    ft_str_malloc(char ***s1, char ***s2, int size, int extra, int p, int l);
	int     ft_itoa_andthensome(int nbr, char ***nb);
	int		ft_opp(char *expr);
	int		ft_parcheck(char *str);

	int		ft_add(int n1, int n2);
	int	    ft_sub(int n1, int n2);
	int	    ft_mul(int n1, int n2);
	int	    ft_div(int n1, int n2);
	int	    ft_mod(int n1, int n2);
	int	    ft_usage(int n1, int n2);
	
#endif
