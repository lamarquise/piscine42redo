#ifndef	_SORT_H_

	#define	_SORT_H_
	
	#include <stdlib.h>

	#define	IS_WSPACE(x) (((x) >= 9 && (x) <= 13) || (x) == 32 || (x) == 0)
	
	char	**ft_split_whitespaces(char *str);
	int		ft_strcmp(char *s1, char *s2);

#endif
