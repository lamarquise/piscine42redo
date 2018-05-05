#include <stdio.h>
#include <unistd.h>

		//Hummm i wonder if i can do this with a single variable...

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (dest[i])
		++i;
	while (src[c])
	{
		dest[i + c] = src[c];		//being weird, its adding the last char a second time at the end, but if this were a string issue, wouldnt there be 2 char added, one 
		++c;						//for each array, hummm...		yea adding \0 worked cool.
	}
	dest[i + c] = '\0';
	return (dest);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%s\n%s\n", argv[1], argv[2]);
		printf("%s\n", ft_strcat(argv[1], argv[2]));
	}
	return (0);
}
