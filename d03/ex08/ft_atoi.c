#include <stdlib.h>
#include <stdio.h>

int		ft_atoi(char *str)
{
	int		i;
	int		ret;
	int		neg;

	ret = 0;
	neg = 1;
	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		++i;
	if (str[i] && str[i] == 45)
	{
		neg = -neg;
		++i;
	}
	else if (str[i] && str[i] == 43)
		++i;
	while (str[i] <= 57 && str[i] >= 48)
	{
		ret = ret * 10 + (str[i] - 48);
		++i;
	}
	return (ret * neg);				//So it works with the exception of huge numbers where the origional atoi gets really weird, so...
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%i\n", atoi(argv[1]));
		printf("%i\n", ft_atoi(argv[1]));
	}
	return (0);
}
