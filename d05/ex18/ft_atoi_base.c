#include <stdio.h>
#include <stdlib.h>

int		base_check(char *base, int *l)
{
	int		c;

	c = 0;											//wait shouldn't this be in the first while loop???
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
	return (*l > 1);								//a trick pascal told me about, lets see if it works
}

int		str_check(char s, char *base)
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
}

int		atoi_ification(char *str, int *neg)			//should still work even if using weird symbols from base, cuz don't handle that here, stops before get to that
{													//by definition, here we just get rid of whitespaces and + or -
	int		i;

	i = 0;
	*neg = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		++i;
	if (str[i] && str[i] == 45)
	{
		*neg = -1;
		++i;
	}
	else if (str[i] && str[i] == 43)
		++i;
	return (i);										//in theory this is where the number part of string starts
}

int		symtonbr_convert(char nb, char *base)
{
	int		i;

	i = 0;
	while (nb != base[i] && base[i])
		++i;
	return (i);
}

int		ft_atoi_base(char *str, char *base)			//ok if you want to make this program run in their weird way that isn't really atoi like anymore, where any symbol
{													//in str that isnt in base invalidates all str, if that's what you want, just send a pointer to neg in str_check
	int		i;										//and if str_check fails, make neg = 0, boom
	int		ret;
	int		l;
	int		neg;
	
	i = atoi_ification(str, &neg);
	ret = 0;
	if (base_check(base, &l) >= 1)
	{
		while (str[i] && str_check(str[i], base) == 1)
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
