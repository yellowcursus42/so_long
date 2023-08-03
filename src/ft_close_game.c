#include "so_long.h"

int	ft_close_win(t_game *game)
{
	ft_printf(CYAN"Movements: %d\n"RESET, ++game->movements);
	ft_printf(GREEN"YOU WIN\n"RESET);
	exit(EXIT_SUCCESS);
}

int	ft_close_by_user(t_game *game)
{
	ft_printf(CYAN"Movements: %d\n"RESET, game->movements);
	ft_printf(GREY"CLOSED\n"RESET);
	exit(EXIT_SUCCESS);
}

int	ft_error_msg(char *message)
{
	ft_printf(RED"Error\n"GREY"%s\n"RESET, message);
	return false;
}
