#include <stdio.h>
#include <stdlib.h>

		//i think it's good to go

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[c] && c == 0)
		{
			while (str[i] == to_find[c] && to_find[c] != '\0')
			{
				++i;
				++c;
			}
			if (to_find[c] == '\0')
				return (&str[i - c]);
		}
		++i;
	}
	return (&str[i]);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%s\n%s\n", argv[1], argv[2]);
		printf("%s\n", ft_strstr(argv[1], argv[2]));
	}
	return (0);
}
