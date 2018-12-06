#include "libft.h"

int		ft_voidlen(unsigned int *src)
{
	int		i;
	int		counter;

	counter = 0;
	i = -1;
	while (src[++i])
		counter += nbr_bytes(src[i]);
	return (counter);
}
