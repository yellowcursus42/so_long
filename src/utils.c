#include "so_long.h"

int	get_first_emptyline_index(char *map)
{
	int i;

	i = 0;
	if (map[0] == '\n')
		return (0);
	else if (map[ft_strlen(map) - 1] == '\n')
		return (ft_strlen(map) - 1);
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_error_msg(char *message)
{
	ft_printf(RED"Error\n"GREY"%s\n"RESET, message);
	return false;
}
