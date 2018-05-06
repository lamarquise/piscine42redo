#include <stdio.h>
#include <stdlib.h>

int		base_check(char *base, int *l)
{
	int		c;

	c = 0;
	*l = 0;
	while (base[*l])
	{
		while (base[c])
		{
			if (base[*l] == base[c] && *l != c)
				return (0);
			++c;
		}
		if (base[*l] == 43 || base[*l] == 45)
			return (0);
		++*l;
	}
/*	if (*l <= 1)
		return (0);
	return (1);		*/
	return (*l > 1);			//a trick pascal told me about, lets see if it works
}

int		str_check(char s, char *base)		//ok so we're totally changing this
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (s == base[i])
			return (1);
		++i;
	}
	return (0);
/*
	int		i;
	int		c;
	int		d;

	d = 0;
	i = 0;
	while (str[i])
	{
		c = 0;
		while (base[c])
		{
			if (str[i] == base[c])
				++d;
			++c;
		}
		++i;
	}
	if (i != d)				//could do same as base_check here
		return (0);
	return (1);		*/
}

int		atoi_ification(char *str, int *neg)		//should still work even if using weird symbols from base, cuz don't handle that here, stops before get to that
{															//by definition, here we just get rid of whitespaces and + or -
	int		i;

	i = 0;
	*neg = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])		//get's rid of whitespaces
		++i;
	if (str[i] && str[i] == 45)
	{
		*neg = -1;
		++i;
	}
	else if (str[i] && str[i] == 43)
		++i;
	return (i);		//in theory this is where the number part starts
}

int		symtonbr_convert(char nb, char *base)
{
	int		i;

	i = 0;
	while (nb != base[i] && base[i])
		++i;
	return (i);
}

int		ft_atoi_base(char *str, char *base)		//shit, we're forgeting the end part of atoi, it stops after it gets to no longer a number, but mine doesn't, humm
{												//might need to do some restructuring of the architecture
	int		i;
	int		ret;
	int		l;
//	char	*s;			//ok so how do i initialize this without initializing it, i thought that's what that loop was for
	int		neg;
	
	i = atoi_ification(str, &neg);
	ret = 0;
/*	while (str[i])		//may not need this part, or *s
	{
		s[ret] = str[i];
		++i;
		++ret;
	}
	ret = 0;	
	i = 0;		*/
	if (base_check(base, &l) >= 1) 		//&& str_check(s, base) == 1)
	{
		while (str[i] && str_check(str[i], base) == 1)				//s[i])
		{
			ret = ret * l + (symtonbr_convert(str[i], base));
			++i;
		}
	}
	return (ret * neg);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%s\n%s\n", argv[1], argv[2]);
		printf("%i\n", ft_atoi_base(argv[1], argv[2]));
	}
	return (0);
}








