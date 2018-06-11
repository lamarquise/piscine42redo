#include <unistd.h>
#include <stdio.h>

			//Taking a break, maybe permanantly untill the Piscine...

void	ft_putchar(char c)
{
	write(1, &c, c);
}

void	print_address(unsigned long long n)		//OK so this used to work fine, but now it doesn't at all... SMH
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		print_address(n / 16);
	putchar(hex[n % 16]);
}

void	hex_print(char c, unsigned int j)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
	if (j % 2 == 0)
		ft_putchar(' ');
}

void	print_char(char c)
{
	if (c >= 32 && c<= 126)
		ft_putchar(c);
	else
		ft_putchar('.');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size)
	{
		print_address((unsigned long long)addr + i);
		putchar(':');
		putchar(' ');
		j = i;
		while (++j < 16 + i && j < size)
			hex_print(*(char*)(addr + j - 1), j);
		ft_putchar(' ');
		j = i;
		while (++j < 16 + i && j < size)
			print_char(*(char*)(addr + j - 1));
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}

int		main(int argc, char *argv[])
{
	unsigned int	i;
	void	*ptr;

	i = 0;
	ptr = &argv[1];
	while (argv[1][i])
	{
		++i;
	}
	if (argc == 2)
	{
		printf("%i\n", i);
		printf("%p\n", ptr);
		printf("%s\n", argv[1]);
		ft_print_memory(ptr, i);
	}
	return (0);
}
