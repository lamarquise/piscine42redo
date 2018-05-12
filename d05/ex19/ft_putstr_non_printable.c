#include <unistd.h>
#include <stdio.h>

	//God damn it took me way too long to figure this out, j'me suis bien pris la tete, wtf. This was a lot simpler than i thought it was

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
