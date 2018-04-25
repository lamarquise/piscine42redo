#include <stdio.h>
#include <stdlib.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	if (s1[i] > s2[i])
		return (1);
	else if (s1[i] < s2[i])
		return (-1);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 4)
		printf("%s\n%s\n%i\n%i\n", argv[1], argv[2], atoi(argv[3]), ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	return (0);
}
