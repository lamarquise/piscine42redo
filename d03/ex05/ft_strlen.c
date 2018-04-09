#include <stdio.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')		//works becasue after gets to last char, adds 1, so isnt missing 1 (tables starting at 0 BS)
		++i;
	return (i);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%i\n", ft_strlen(argv[1]));
	return (0);
}
