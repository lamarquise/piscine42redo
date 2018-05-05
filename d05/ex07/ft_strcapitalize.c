#include <stdio.h>

		//Once again, seems to work to me, but i haven't hardcore tried to break it, so... presumable when im in the piscine, i can find out more easily what will break it.

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122 && (((str[i - 1] >= 9 && str[i - 1] <= 13) || str[i - 1] == 32) || i == 0))
			str[i] = str[i] - 32;
		else if (str[i] >= 65 && str[i] <= 90 && !(((str[i - 1] >= 9 && str[i - 1] <= 13) || str[i - 1] == 32) || i == 0))
			str[i] = str[i] + 32;
		++i;
	}
	return (str);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s\n", argv[1]);
		printf("%s\n", ft_strcapitalize(argv[1]));
	}
	return (0);
}
