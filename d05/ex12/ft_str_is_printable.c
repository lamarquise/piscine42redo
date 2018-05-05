#include <stdio.h>

		//hold up, \0 is NULL, is non printable, but you need that for the end of the string, it would seem not, it works when \0 included in return 0,
		//I think this is because loop ends when reaches \0, so doesnt get the opportunity to return 0...

int		ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 0 && str[i] <= 31)
			return (0);
		++i;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%s\n%i\n", argv[1], ft_str_is_printable(argv[1]));
	return (0);
}
