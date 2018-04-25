#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	return (dest);
}

int		main(int argc, char * argv[])		//ok so honestly the main is more complicated than the function, cuz of allocation and shit, mo fos!!!
{
	char	src[30];
	char	dest[30];
	int		i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		src[i] = argv[1][i];
		++i;
	}
	src[i + 1] = '\0';
	if (argc == 2)
	{
		printf("%s\n", src);
		printf("%s\n", ft_strcpy(dest, src));
	}
	return (0);
}
