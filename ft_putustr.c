#include "libft.h"

int		ft_putustr(unsigned int *str)
{
	int	i;
	int	counter;

	counter = 0;
	i = -1;
	while (str[++i])
		counter += ft_putuchar(str[i]);
	return (counter);
}
