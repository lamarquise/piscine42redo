#include <stdio.h>
#include <stdlib.h>
#include <string.h>

		//So I have no idea if im telling it the max size with the unsigned int size, or if im return how long it ended up being after both strings combined with size,
		//Or maybe it tell it how long it's supposed to be and it then confirmes that it is that long, or some shit...

	//UHHHHG i fucking hate this...

//size_t
strlcat(char *dst, const char *src, size_t size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (dest[i])
		++i;
	while (src[c])
	{
		dest[i + c] = src[c];
		++c;
	}
	dest[i + c] = '\0';

	return (size);
}

int		main(int argc, char *argv[])
{

	if (argc == 4)
	{
		printf("%i\n", strlcat(argv[1], argv[2], atoi(argv[3])));
	//	printf("%s\n%s\n%i\n", argv[1], argv[2], atoi(argv[3]));
	//	printf("%i", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}
