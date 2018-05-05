#include <stdio.h>
#include <string.h>

		//wait, what about whitespaces, how do we treat them??? i suspect they would return 0, but asked Pascal, i was right
//int		isalpha(int c);		whatever, isalpha is sooo anoying

int		ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)))
			return (0);
		++i;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%s\n%i\n", argv[1], ft_str_is_alpha(argv[1]));
	return (0);
}
