#include "adv_do_op.h"

void	ft_add(int n1, int n2)
{
	ft_putnbr(n1 + n2);
}

void	ft_sub(int n1, int n2)
{
	ft_putnbr(n1 - n2);
}

void    ft_mul(int n1, int n2)
{
	ft_putnbr(n1 * n2);
}

void    ft_div(int n1, int n2)
{
	if (n2 != 0)
		ft_putnbr(n1 / n2);
	else
		write(1, "Stop : division by 0\n", 22);
}

void    ft_mod(int n1, int n2)
{
	if (n2 != 0)
		ft_putnbr(n1 % n2);
	else
		write(1, "Stop : modulo by 0\n", 20);
}

void	ft_usage(int n1, int n2)
{
	n1 = 4;
	n2 = 10;
	write(1, "error : only [ - + * / % ] are accepted\n", n1 * n2);
}
