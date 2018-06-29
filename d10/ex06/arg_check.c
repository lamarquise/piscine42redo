#include "do_op.h"

	//ok so first using a simplified version just as an op_check.

int		arg_check(char *op)					//(char *n1, char *op, char *n2)
{
/*	char	*ans[3];
	
	ans[0] = "0";
	ans[1] = "Stop : division by 0";
	ans[2] = "Stop : modulo by 0";

	//yea not sure i want to do it this way, but i guess i can come back to it if i have to
*/
	int		i;

	i = 0;
	while (op[i])
	{
		if (op[i] != '+' && op[i] != '-' && op[i] != '*' && op[i] != '/' && op[i] != '%')
			return (0);
		++i;
	}
	if (i > 1)
		return (0);
	return (1);
}
