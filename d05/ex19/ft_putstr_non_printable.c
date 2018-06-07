#include <unistd.h>
#include <stdio.h>

	//God damn it took me way too long to figure this out, j'me suis bien pris la tete, wtf. This was a lot simpler than i thought it was

	//Just FYI, to get the a.out to run, i use a $'string' format for the argument, $ makes it interpret \n as a carage return rather than as 2 seperate characters,
	//but that's fine, the program isnt supposed to handle that, if anything, it's the main's job to make sure that happens, but i don't have to make that be the case
	//cuz i can just use $, oh and "" don't work you have to use '' :)

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	hex_print(int n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		hex_print(n / 16);
	putchar(hex[n % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
		{
			putchar('\\');
			if (str[i] < 16)
				putchar('0');
			hex_print(str[i]);
			++i;
		}
		putchar(str[i]);
		++i;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s\n", argv[1]);
		ft_putstr_non_printable(argv[1]);
	}
	return (0);
}
