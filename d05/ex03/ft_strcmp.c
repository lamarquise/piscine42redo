#include <stdio.h>
#include <stdlib.h>

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])		//once gets to a char that isnt the same, compares ascii valuse, works if 1 str is shorther than other
		++i;
	if (s1[i] > s2[i])
		return (1);
	else if (s1[i] < s2[i])
		return (-1);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		printf("%s\n%s\n%i\n", argv[1], argv[2], ft_strcmp(argv[1], argv[2]));
	return (0);
}
