#include "adv_do_op.h"
#include "ft_opp.h"

int		ft_strcompare(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return (*s2 - *s1);
}

int		opp_check(char *op)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (ft_strcompare(op, gl_opptab[i].op) == 0)
			return(i);
		++i;
	}
	return (5);
}

int		main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	else if (opp_check(argv[2]) >= 0)
		gl_opptab[opp_check(argv[2])].f(ft_atoi(argv[1]), ft_atoi(argv[3]));
	return (0);
}
