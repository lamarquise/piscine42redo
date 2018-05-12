#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)		//wait, the function has to display, doesnt have to change the string, hummm
{							//well that fucking worked, cool, that said, still not sure if my program working the way it's supposed to, 
	write(1, &c, 1);		//im using a shell comand, $'string' to make it consider \n and non printables as what they are
}						//also when i use like \0, it just ends, is that ok?

void	str_len(char *str, int *l)		//was int, now void
{
	*l = 0;
	while (str[*l])
		++*l;
//	return (*l);
}

void	str_shift(char *str, int i, int l)		//fuck, the amount it is shifted depends on the non printable char, could be 1 or 2 digits
{
	while (l >= i + 1)									//could do all in one go if replace 1 with n and send n
	{
		str[l + 1] = str[l];
		--l;
	}
}								//ok so this one does need to be + 3

void	hex_replace(char *str, int i, int c, int n)		//hex is 0123456789abcdef
{
	
	char	hex[16];
	int		l;
	int		m;

	m = 0;
	while (m < 16)
	{
		hex[m] = 48 + m;
		if (m > 9)
			hex[m] = hex[m] + 39;
		++m;
	}
//	l = str_len(str, &l);		//this or the func are redundant, either return or pointer, not both
	str_len(str, &l);
//	str_shift(str, i, l);
	if (c == 0)
	{
	//	str_shift(str, i, l);
	//	str[i] = '\\';
		putchar('\\');
		hex_replace(str, i, c + 1, n);
	}
	else if (c > 0 && n > 16)		//this is a problem aria, was >= 16
	{
	//	str_shift(str, i, l);
		hex_replace(str, i, c + 1, n / 16);				//not sure this model works
		putchar(hex[n % 16]);
	}
	else if (c == 1 && n < 16)
	{
		putchar('0');
		putchar(hex[n % 16]);
	}
}

void	ft_putstr_non_printable(char *str)		//ok need to rethink the architecture, should do the hex conversion first so can tell the shift how much to shift
{
	int		i;
//	int		l;
	int		c;
	int		n;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
		{
			c = 0;
			n = str[i];					//could put str_shift(str, i, l); here, would need to add l though
			hex_replace(str, i, c, n);
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
	//	write(1, "hello\nworld", 11);
		ft_putstr_non_printable(argv[1]);
	}
	return (0);
}
