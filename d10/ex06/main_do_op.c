#include "do_op.h"

			//WELL surprisingly it works, still needs some debuging and more whatever error messages stuff, but it works




		//I suppose we could process some things in the main, but like why bother?

		//ok so this project is getting a bit overbloated, like there are redundancies everywhere, i think i might need something to stay more organized, maybe atom
		//I guess we'll see...

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
/*		if (!(ft_atoi(argv[1]) >= 48 && ft_atoi(argv[1]) <= 57) || !(ft_atoi(argv[3]) >= 48 && ft_atoi(argv[3]) <= 57))
		{
			write(1, '0', 1);
			return (0);
		}	*/
//		write(1, "huh\n", 4);
		if (arg_check(argv[2]) != 1)
		{
			write(1, "0\n", 2);
			return (0);
		}
//		write(1, "yo\n", 3);
		do_op(ft_atoi(argv[1]), argv[2], ft_atoi(argv[3]));
//		write(1, "still\n", 6);
	}
	return (0);
}
