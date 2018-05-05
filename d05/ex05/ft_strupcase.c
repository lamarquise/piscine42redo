#include <stdio.h>
#include <stdlib.h>

		//I am skeptical that it would be this simple, but it does work, so until proven otherwise, this seems to be the answere to their question.

char	*ft_strupcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 122 && str[i] >= 97)
			str[i] = str[i] - 32;
		++i;
	}
	return (str);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s\n", argv[1]);						//have to use 2 printf's or origional argv[1] is never printed, it is chaneged before it gets that far.
		printf("%s\n", ft_strupcase(argv[1]));
	}
	return (0);
}
