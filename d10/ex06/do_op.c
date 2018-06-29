#include "do_op.h"

		//there has to be a more elegant way of handling litterally all of this, uhhhg, this is gross...

void	do_op(int n1, char *op, int n2)
{
	int		res;
	
	if (*op == '+')
		res = n1 + n2;			//duhhh you fuckin moron.
//		res = ft_add(n1, n2);
	else if (*op == '-')
		res = n1 - n2;
//		res = ft_sub(n1, n2);
	else if (*op == '*')
		res = n1 * n2;
//		res = ft_mult(n1, n2);
	else if (*op == '/')
		res = n1 / n2;
//		res = ft_div(n1, n2);
	else if (*op == '%')
		res = n1 % n2;
//		res = ft_mod(n1, n2);
	else
		res = 0;
	ft_putnbr(res);
	write(1, "\n", 1);
}
