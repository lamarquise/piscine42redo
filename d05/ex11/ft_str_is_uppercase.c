#include <stdio.h>

int		ft_str_is_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 65 && str[i] <= 90))
			return (0);
		++i;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%s\n%i\n", argv[1], ft_str_is_uppercase(argv[1]));
	return (0);
}
