#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		++i;
	}
	return (str);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s\n", argv[1]);					//see ex06 for explanation
		printf("%s\n", ft_strlowcase(argv[1]));
	}
	return (0);
}
