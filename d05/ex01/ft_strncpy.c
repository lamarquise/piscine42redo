#include <string.h>		//for comparing with actual strncpy function
#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')		//more comprehensive with + 1 and = as opposed to just <
	{
		if (i + 1 <= n)
			dest[i] = src[i];
		else
			dest[i] = '\0';
		++i;
	}
	return (dest);
}

int		main(int argc, char *argv[])		//wait is this correct, should my function be able to handle a dest string of any size, or is that supposed to be handled before?
{											//i think im good, according to the internet, lol
	char	dest[30];

	if (argc == 3)
	{
		printf("%i\n%s\n", atoi(argv[2]), argv[1]);		//i mean could prolly have these printfs in a a single one, but whatever
		printf("%s\n", ft_strncpy(dest, argv[1], atoi(argv[2])));			//could prolly also just send argv[1] instead of src, yup that works, so i did it
	}
	return (0);
}
