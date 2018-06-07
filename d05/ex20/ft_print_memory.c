#include <unistd.h>
#include <stdio.h>

			//Damn, can't do anything until we get that answer...

void	ft_putchar(char c)
{
	write(1, &c, c);
}

void	print_address(unsigned long n)		//OK so we're going to leave this as is, Pascal did it differently, but it seems to be find like this, and it works so...
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		print_address(n / 16);
	putchar(hex[n % 16]);
}

void	hex_print(it gets a character and a value that tells it to print " " or not)
{
	char	*hex;

	hex = "0123456789abcdef";

}

void	print_char(gets a character and either prints . or char)
{
	
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	c;
	char	*ch;

	i = 0;										//ok so im still pretty lost, no idea how to make this work, i understand the theory, but don't know how to implement
	c = 1;										//so im taking a break, gonna work on d06 for a bit.
//	while (i < size)
//	{
		print_address((unsigned long)addr + i);		//Effectively this just prints the address, easy peasy there is no base change
		putchar(':');
		putchar(' ');
		




//		while (i <= c * 16)
//		{
	//		ch = addr;					//this compiles but mostly useless, tried *ch = &address, didnt compile, but kinda makes sense
	//		hex_print(*ch);				
			hex_print(*(char*)addr);
	//		hex_print((unsigned long)&addr);
/*			putchar(' ');
			i = i + 1;	//was 2
		}
		++c;
	//	- something clever
	
	}
*/	return (addr); 	//OK so i tried printf ing this return in main, i tried casting the return to a char*, printed some weird shit, then i returned (*addr) and it fliped out
}					//So i guess, who the fuck knows what's going on...

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
//		printf("%i\n", i);
//		printf("%p\n", ptr);
//		printf("%s\n", argv[1]);
		ft_print_memory(ptr, i);
	}
	return (0);
}
