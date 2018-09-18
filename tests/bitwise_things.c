//		| & ^ << >> 
//		


//		'a' works
//		a has to be an assigned variable
//		char a = 44;



void		print_bits(char c)
{
	int 	i;

	i = 8;
	while (--i >= 0)
	{
		if (c & (1 << i))
			print 1;
		else 
			oirnt 0;
	}
}

char	swat_bits(char c)
{
	return ((c >> 4) + (c << 4))			//or use | but aight
}

char	rev_bits(char c)
{
	int		i;
	char	ret;

	i = 8;
	ret = 0;
	while (--i >= 0)
	{
		if (c & (1 << i))
			ret |= (1 << (7 - i));
			ret |= (128 >> i);				//one of these
	}
	return (ret);
}
