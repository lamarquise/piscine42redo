#include <stdio.h>
#include <stdlib.h>

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (dest[i])
		++i;
	while (src[c] && c < nb)
	{
		dest[i + c] = src[c];
		++c;
	}
	dest[i + c] = '\0';
	return (dest);
}

int		main(int argc, char *argv[])
{
	if (argc == 4)
	{
		printf("%s\n%s\n%i\n", argv[1], argv[2], atoi(argv[3]));
		printf("%s\n", ft_strncat(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}
