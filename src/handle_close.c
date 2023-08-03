#include "so_long.h"

int	handle_close_win(t_game *game)
{
	ft_printf(CYAN"Movements: %d\n"RESET, ++game->movements);
	ft_printf(GREEN"YOU WIN\n"RESET);
	exit(EXIT_SUCCESS);
}

int	handle_close_user(t_game *game)
{
	ft_printf(CYAN"Movements: %d\n"RESET, game->movements);
	ft_printf(GREY"CLOSED\n"RESET);
	exit(EXIT_SUCCESS);
}
