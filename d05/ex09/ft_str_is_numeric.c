#include <stdio.h>

int		ft_str_is_numeric(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		++i;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%s\n%i\n", argv[1], ft_str_is_numeric(argv[1]));
	return (0);
}
