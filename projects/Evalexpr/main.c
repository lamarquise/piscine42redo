#include "eval.h"


void	ft_str_malloc(char ***s1, char ***s2, int size, int extra, int p, int l)		//copies s1 to s2, s1[p] s2[l]
{
	int		i;
	
	i = 0;
//	printf("Malloc start test.\n");
//	printf("Malloc s2[0] tmp test: %s\n", (*s2)[0]);
	(*s2)[l] = malloc(size);
	while ((*s1)[p][i])
	{
		(*s2)[l][i + extra] = (*s1)[p][i];
		++i;
	}
	(*s2)[l][i + extra] = '\0';
//	printf("Malloc s2[0] tmp test, the address: %d\n", &s2[0]);			//havent gotten this to work yet, but could be helpful to solve my weird problem

//	printf("Malloc end test.\n");
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		ft_itoa_andthensome(int nbr, char ***nb)			//so returns len of str that will be inserted and converts int to that str
{
	int		size;
	char	*dec;
	char	**tmp;
	int		p;

	dec = "0123456789";
	size = 2;
	p = 0;
//	printf("test in itoa\n");
	(*nb) = malloc(2);
	tmp = malloc(1);
	(*nb)[1] = 0;
	(*nb)[0] = malloc(size);
	(*nb)[0][0] = ' ';				//that should be the space after the insert handled
	(*nb)[0][1] = '\0';

	if (nbr < 0)
		p = 1;
//	printf("test\n");
	while (ABS(nbr) >= 1)
	{
//		printf("test begin loop\n");
		ft_str_malloc(nb, &tmp, size, 0, 0, 0);
//		printf("test mid loop\n");
		ft_str_malloc(&tmp, nb, ++size, 1, 0, 0);
//		printf("test mid loop 2\n");
		(*nb)[0][0] = dec[ABS(nbr) % 10];		//for some reason this didn't work...					//replaced all (*nb) with nb[0]
//		printf("test end loop\n");
		nbr = nbr / 10;
//		printf("nb[0][0]: %c\n", nb[0][0]);
	}
	ft_str_malloc(nb, &tmp, size, 0, 0, 0);
	if (p == 0)
		ft_str_malloc(&tmp, nb, ++size, 1, 0, 0);
	else if (p == 1)
	{
		ft_str_malloc(&tmp, nb, ++size, 2, 0, 0);
		(*nb)[0][1] = '-';
	}											//ok so that's the space before the insert handled
	(*nb)[0][0] = ' ';
//	printf("string nb is: %s, ITOA Successful\n", (*nb)[0]);
	return (size - 1 + p);
}

void	ft_replace(char **expr, int snip, int len, int start)				//i can;t believe this sort of works !?
{
	char	**repl;
	char	**nb;
	int		i;
	int		b;

	i = 0;
	b = 0;

//	printf("Expr at begin of ft_replace: %s\n", (*expr));

	snip = ft_itoa_andthensome(snip, &nb);
	repl = malloc(2);
	repl[1] = 0;
	repl[0] = malloc(ft_strlen((*expr)) - len + snip);		//might need a +1 for \0.....
	while (i < start)		
	{
		repl[0][i] = (*expr)[i];							//copies until the inner most ()
		++i;
	}

//	printf("repl before (): %s\n", repl[0]);

	while (b < snip)
	{
		repl[0][i + b] = nb[0][b];							//copies what the inner most () have been replaced with
		++b;
	}

//	printf("repl with sol of (): %s\n\n", repl[0]);
//	printf("Test expr: %s\n", *expr);

	while (i < ft_strlen(*expr))				//so this could be the problem...
	{												//will this + 1 fix everything????
		repl[0][i + snip] = (*expr)[i + len + 1];				//copies what is left,		(*expr) as opposed to expr[0] makes me nervous
		++i;
	}

//	printf("repl after end added back on: %s\n", repl[0]);

//	repl[0][i + snip] = '\0';			//not sure if needed
	ft_str_malloc(&repl, &expr, i + snip, 0, 0, 0);					//should work....

//	printf("Expr at end of ft_replace: %s\n", (*expr));
}

void	ft_reduce(char **expr)			//ok so this func cuts out the inner most () and calls func to replace that with answer
{
	int		i;
	int		c;
	int		s;
	char	*op;

	i = 0;
//	printf("strlen expr: %i\n", ft_strlen(*expr));
	while ((*expr)[i])
	{
		if ((*expr)[i] == ')')
		{
			c = i;
			while ((*expr)[c] != '(')
				--c;
			op = malloc(i - c);
			s = 0;
			while (c <= i)
			{
				op[s] = (*expr)[c];				//creates op = to inner most () of expr
				++c;
				++s;															//ft_replace should be good to go, i just need to set up ft_opp now...
			}
//			printf("op i.e. inner most () in ft_reduce: %s\n", op);
			ft_replace(expr, ft_opp(op), ft_strlen(op), i - ft_strlen(op));		//this is where expr gets edited and op is inserted to replace inner most ()
		i = ft_strlen(*expr);	//ft_opp is snip which eventually become = to len of what is placed, ft_strlen is len of what is removed
		}
		//hummm will this loop make the loop in eval_expr redundant??? or is it just also helpful, or we could do i = strlen(expr) at the end so it just ends
		//ok so i was right, it does do both if there are 2 parallel sets of (), for now just handle one at a time, but could be intersting to do both at the same time.
		++i;
	}
}

int		ft_par_count(char *expr)			//This func just counts the paires of () returns that, nothing else, doesn's change anything
{
	int		i;
	int		s;

	s = 0;
	i = 0;
	while (expr[i])
	{
		if (expr[i] == '(')
			++s;
		++i;
	}
	return (s);
}

int		eval_expr(char *str)		//purpose is to one by one remove sets of (), then return an int
{
	while (ft_par_count(str) != 0)
	{
//		printf("Str in eval_expr %s.\n", str);
		ft_reduce(&str);						//we need to make sure str is modified 
	}

			//if around here i add another call to do-op, that would also be able to handle multiple ops, this along side the call to do-op in (), it would first do the ops 
			//in () then do the ops outside of () which would also handle the case when there are no ().... DONE, see below.

	return (ft_opp(str));
}

int		main(int ac, char **av)
{
/*	char	**nb;

	if (ac > 1)
	{
		printf("Size %i\n", ft_itoa_andthensome(atoi(av[1]), &nb));		//when test this ./a.out "a number + or -"
		printf("test2\n");
		printf("nb sent back: %s\n", nb[0]);				//ok so for some strange reason this isnt working...
//		ft_putchar(nb[0][0]);
	}
*/

	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}	
	return (0);
}		

