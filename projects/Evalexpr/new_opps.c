#include "eval.h"

	//will need to be changed, send to a func that handles the overal op and that one will return to a print func once done, or something like that.

int		ft_add(int n1, int n2)
{
	return (n1 + n2);					//ft_replace or something???
}

int		ft_sub(int n1, int n2)
{
	return (n1 - n2);
}

int    ft_mul(int n1, int n2)
{
	return (n1 * n2);
}

int    ft_div(int n1, int n2)
{
	if (n2 != 0)
		return (n1 / n2);
	else
		write(1, "Stop : division by 0\n", 22);
	return (0);											//ok so i guess this means the program will still work even if you fuck up one of the ops
}

int    ft_mod(int n1, int n2)
{
	if (n2 != 0)
		return (n1 % n2);
	else
		write(1, "Stop : modulo by 0\n", 20);
	return (0);
}

int		ft_usage(int n1, int n2)
{
	n1 = 4;
	n2 = 10;
	write(1, "error : only [ - + * / % ] are accepted\n", n1 * n2);
	return (0);
}
