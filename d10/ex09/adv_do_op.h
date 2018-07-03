#ifndef	__ADV_DO_OP_H__

	#define	_ADV_DO_OP_H__

	#include <unistd.h>
	
	typedef struct	s_opp
	{
		char *op;
		void (*f)(int, int);
	}				t_opp;

	int		ft_atoi(char *str);
	void	ft_putnbr(int nb);

	void	ft_add(int n1, int n2);
	void    ft_sub(int n1, int n2);
	void    ft_mul(int n1, int n2);
	void    ft_div(int n1, int n2);
	void    ft_mod(int n1, int n2);
	void    ft_usage(int n1, int n2);
	
#endif
