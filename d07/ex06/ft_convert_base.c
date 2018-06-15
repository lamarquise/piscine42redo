#include <stdlib.h>
#include <stdio.h>

		//End of day 5 is where the 

int		base_check(char *base, int *l)							//Ok so this both verifies that a base is valid and returns the length of that base, useful
{
	int		c;

	*l = 0;
	while (base[*l])
	{
		c = 0;
		while (base[c])
		{
			if (base[c] == base[*l] && *l != c)
				return (0);
			++c;
		}
		if (base[*l] == '+' || base[*l] == '-')
			return (0);
		++*l;
	}
	if (*l <= 1)
		return (0);
	return (1);
}

int		symbol_convert(char nb, char *base)
{
	int		i;

	i = 0;
	while (nb != base[i] && base[i])
		++i;
	return (i);
}	

int		base10ification(char *nbr, char *base_from)
{
	int		i;
	int		ret;												//nbr in base 10 and now an int
	int		l;
	int		neg;

	i = 0;
	neg = 1;
	ret = 0;
	if (base_check(base_from, &l) == 1)
	{
		if (nbr[0] == '+')
			++i;
		else if (nbr[0] == '-')
		{
			neg = -1;
			++i;					//shorter?
		}
		while (nbr[i])
		{
			ret = ret * l + symbol_convert(nbr[i], base_from);
			++i;
		}
	}
	return (ret * neg);
}

char	*convert_to_new_base(int number, int *n, char *base_to, char *nbr)
{																				//Some shit where if number is neg, never change nbr[0] have it set to '-'
	char	*tab;
	int		i;
	int		l;

	if (base_check(base_to, &l) == 0)
		return (0);
	nbr = malloc(sizeof(char) * 1);					//could you get rid of these lines?
	nbr[0] = '\0';
	while (number >= 1)
	{
		i = 0;
		tab = malloc(sizeof(char) * (*n));			//could do ++*n maybe
		while (nbr[i])
		{
			tab[i] = nbr[i];						//can make shorter
			++i;
		}
		free(nbr);									//are you using free right?
		nbr = malloc(sizeof(char) * (*n + 1));
		i = 0;
		while (tab[i])
		{
			nbr[i + 1] = tab[i];					//could also make this shorter
			++i;
		}
		nbr[0] = base_to[number % l];
		free(tab);
		number = number / l;
		++*n;
	}
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)		//since moving most of base convert to another function, use space to handle + and - similar structure
{
	int		n;
	int		number;
	char	*tab;
	int		i;

	n = 1;
	number = base10ification(nbr, base_from);
	if (number < 0)
	{
		convert_to_new_base(number, &n, base_to, nbr);			//yea im not sure how to put this part in the convert_to_new_base function, it would be handy but...
		i = 0;
		convert_to_new_base(number * -1, &n, base_to, nbr);
		tab = malloc(sizeof(char) * n);
		while (nbr[i])
		{
			tab[i] = nbr[i];
			++i;
		}
		nbr = malloc(sizeof(char) * n + 1);
		i = 0;
		while (tab[i])
		{
			nbr[i + 1] = tab[i];								//HOLD ON, NO idea how, but it already handles negative numbers, WTF!?
			++i;
		}
		nbr[0] = '-';
		return (nbr);
	}
	return (convert_to_new_base(number, &n, base_to, nbr));
}

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%s\n%s, %s\n", argv[1], argv[2], argv[3]);
		printf("My return: %s\n", ft_convert_base(argv[1], argv[2], argv[3]));
	}
	return (0);
}
