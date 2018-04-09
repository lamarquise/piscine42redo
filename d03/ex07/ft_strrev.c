#include <stdio.h>

char	*ft_rev(char *str, int i)
{
	char	temp[i];
	int		c;
	int		d;

	d = i;
	c = 0;
	while (c <= i)
	{
		temp[c] = str[d];
		++c;
		--d;
	}
	while (d <= i)
	{
		str[d] = temp[d];
		++d;
	}
	return (str);
}

char	*ft_strrev(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		++i;
	--i;						//becasue i becomes length not array position
	ft_rev(str, i);
	return (str);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s\n", argv[1]);
		printf("%s\n", ft_strrev(argv[1]));
	}
	return (0);
}
