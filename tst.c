#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/game.h"

int	f(char *s)
{
	char	*tmp;
	char	empty[5];
	int		i;
	int		j;

	tmp = s;
	j = 0;
	i = ft_strlen(s);
	if (i < 4)
		return (-1);
	tmp += i - 1;
	while (j < 4)
	{
		empty[j] = *tmp;
		j++;
		tmp--;	
	}
	empty[4] = 0;
	return (ft_strncmp(empty, "reb.", 4));
}

int main(int argc, char const *argv[])
{
	printf("%d\n", f(".ber"));
	printf("%d\n", f("/maps/big.ber.txt"));
	return 0;
}
