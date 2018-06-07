#include <unistd.h>

			//go look at d03 ex09 and d05 ex03

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		compare(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	if (s1[i] > s2[i])
		return (2);
	return (1); 		//ie else if s1[i] <= s2[i], but that would be redundant
}

int		main(int argc, char *argv[])			//may need some safeguards like if (argc >= 2) or some shit
{
	int		i;
	int		c;
	int		t[argc - 1];
	
	c = 0;
	i = 0;
	if (argc > 1)
	{
		while (c < argc - 1)		//could prolly make this more concise
		{
			t[c] = c + 1;
			ft_putchar(t[c] + 48);
			ft_putchar('\n');		//Temp
			++c;
		}
		while (i < argc)		//ok so adding this - 1 sort of fixed things but damn do i also get some weird results
		{
			while (compare(argv[i + 1], argv[i + 2]) == 2)		//i suspect this is the problem aria, because in a simple table, at end you have \0
			{
				c = t[i];			//so i went from i to i - 1 and i + 1 to i, cuz i have the tab t, starting at t[0] = 1, not 0, cuz i never need the 0, fewer mishaps.
				t[i] = t[i + 1];
				t[i + 1] = c;			//ok so now i suspect that this might be the main problem aria
				if (i != 1)
					--i;
			}
			++i;
		}
/*		i = 0;
		while (t[i] != '\0')					//ok nvm this is the part that's freaking out.
		{
			c = 0;
			while (argv[t[i]][c] != '\0')
			{
				ft_putchar(argv[t[i]][c]);
				++c;
			}
			write(1, ".", 1);
			ft_putchar('\n');
			++i;
		}
*/	}
	return (0);
}
