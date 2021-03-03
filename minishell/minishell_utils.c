#include "minishell_utils.h"

size_t ft_doubletab_len(char **doubletab)
{
	int	i;
	i = 0;
	while (doubletab[i])
		i++;
	return (i);
}
