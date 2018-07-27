#include "eval.h"
#include "ft_opp.h"

	//ok so this all has to return a single int, through the opp in that pointers to functions table


int		ft_strcmp(char *s1, char *s2)
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
		if (ft_strcmp(op, gl_opptab[i].op) == 0)		//ok so this goes and compares the char (in this case an opperator ideally) with the one in the pointers to funcs
			return(i);										//then when it finds the right one it returns the number referencing the function for that opperation in the tab
		++i;
	}
	return (5);
}

// the 2 functions above are good, we just need to send them the right stuff

int		tab_count(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

int		opp_select(char **tab)							//seems to be working
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (tab[i])
	{
		if (tab[i][0] != '+' && tab[i][0] != '-' && tab[i][0] != '*' && tab[i][0] != '/' && tab[i][0] != '%')
			++i;
		else if (tab[i][0] == '+' || tab[i][0] == '-')
		{
			if (tab[p][0] != '*' && tab[p][0] != '/' && tab[p][0] != '%' && tab[p][0] != '+' && tab[p][0] != '-')
				p = i;
			++i;
		}
		else if (tab[i][0] == '*' || tab[i][0] == '/' || tab[i][0] == '%')
		{
			if (tab[p][0] != '*' && tab[p][0] != '/' && tab[p][0] != '%')
				p = i;
			++i;
		}
	}
	return (p);
}

void	tab_reduce(char ***tab, int p, int res)			//inserts int res turned into an str into tab array at the right place.
{
	char	**tmp;
	char	**nb;
	int		i;
	int		size;
//	int		t;

	size = ft_itoa_andthensome(res, &nb);		//sets size and turns int res into a string saved in nb, not sure i can do this in 3rd ft_str_malloc, might not have nb set
	tmp = malloc(tab_count(*tab) - 1);			//was using minus t to take parcheck into acount, then subtract from the malloc, then same for *tab malloc later

	//test printing
//	printf("this is tab before insert: ");
//	while ((*tab)[i])
//		printf("%s ", (*tab)[i++]);
//	printf("\n");

//	printf("Tmp[0] 1: %s\n", tmp[0]);

	i = 0;
	while (i < p - 1)
	{
		ft_str_malloc(tab, &tmp, ft_strlen((*tab)[i]), 0, i, i);
		++i;
	}

//	printf("Tmp[0] 2: %s\n", tmp[0]);
													//ok so below what am i sending: &nb, the adres of nb, the adress of tmp, the length of nb, the decalage for print 0, 
	ft_str_malloc(&nb, &tmp, size, 0, 0, i);						//ok so this fucks up when there are 4 or more numbers
	++i;									

//	printf("Tmp[0] 3: %s\n", tmp[0]);

	while ((*tab)[i + 2])									//copies the rest of tab array to tmp array
	{
		ft_str_malloc(tab, &tmp, ft_strlen((*tab)[i + 2]), 0, i + 2, i);
		++i;
	}

	tmp[i] = 0;					//super fuckin important!!!!
	++i;

//	printf("Tmp[0] 4: %s\n", tmp[0]);

//	free(*tab);						//this may have tried to destroy everything...
	*tab = malloc(i);


	//test print
//	i = 0;
//	printf("This is tmp at the very end: ");
//	while (tmp[i])
//		printf("%s ", tmp[i++]);
//	printf("\n");
//	printf("Here Tmp[1]: %s\n", tmp[1]);

//	printf("Tmp[0] 4: %s\n", tmp[0]);

	i = 0;
	while (tmp[i])
	{
		ft_str_malloc(&tmp, tab, ft_strlen(tmp[i]), 0, i, i);		//copies tmp back to tab, so tab has the modifications in the right place.
		++i;
	}
	(*tab)[i] = 0;
}

int		ft_parcheck(char *str)						//i have no idea if some numbers are given with ) or ( at the begining or end??? that could fuck this up...
{
	int		i;
	int		c;
												//so i had parcheck in tab_reduce (like in each of the copy to tmp loops), but its actually works in ft_opp so...
	i = 0;
	c = 0;
	while (str[i])									//in theory this should pick out the strings that are only ( or )
	{
		if (str[i] == '(' || str[i] == ')')
			c = 1;
		++i;
	}
	return (c);
}

int		ft_opp(char *expr)
{
	char	**tab;
	int		p;				//the possition in tab of the opperation to be handled 1st
//	int		i;

	tab = ft_split_whitespaces(expr);//incidentally i think splitwhitespaces is the program where Pascal did away with var to cycle through strings, shorter, worth a look...
	
	p = opp_select(tab);
	while (p != 0)				//tab_count(tab) >= 3)
	{
		tab_reduce(&tab, p, gl_opptab[opp_check(tab[p])].f(ft_atoi(tab[p - 1]), ft_atoi(tab[p + 1])));
//		i = 0;
//		printf("This is tab in ft_opp: ");
//		while (tab[i])
//			printf("%s ", tab[i++]);		//we know this works
//		printf("\n");
		p = opp_select(tab);
	}
	p = 0;
	while (tab[p])
	{
		if (ft_parcheck(tab[p]) != 1)
			return (ft_atoi(tab[p]));
		++p;
	}

	return (ft_atoi(tab[0]));		//might work, idk ???		yea i guess it does

}

//test main
/*
int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_opp(argv[1]);
	return (0);
}
*/
