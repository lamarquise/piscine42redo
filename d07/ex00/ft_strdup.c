#include <stdlib.h>
#include <stdio.h>

		//Im sure it could be better but im not gonna sweat it

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;
	int		a;
	
	i = 0;
	a = -1;
	while (src[i])
		++i;
	ret = (char*)malloc(sizeof(*ret) * (i + 1));
	while (++a <= i)
		ret[a] = src[a];
	ret[a] = '\0';
	return (ret);
	free(ret);		//apparently i can do this and it still compiles, not sure if it actually does anything...
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s\n", argv[1]);
		printf("%s\n", ft_strdup(argv[1]));
	}
	return (0);
}
