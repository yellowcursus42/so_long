#include "so_long.h"

int	ft_player_move(t_game *game, int new_y, int new_x)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.coins == 0)
		return ft_close_win(game);
	else if ((game->map.full[new_y][new_x] == FLOOR)
	|| (game->map.full[new_y][new_x] == COINS))
	{
		game->map.full[last_y][last_x] = FLOOR;
		if (game->map.full[new_y][new_x] == COINS)
			game->map.coins--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
		game->movements++;
		ft_render_map(game);
	}
	return true;
}

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		return ft_player_move(game, game->map.player.y - 1, game->map.player.x);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		return ft_player_move(game, game->map.player.y, game->map.player.x - 1);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		return ft_player_move(game, game->map.player.y, game->map.player.x + 1);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		return ft_player_move(game, game->map.player.y + 1, game->map.player.x);
	if (keysym == KEY_Q || keysym == KEY_ESC)
		return ft_close_by_user(game);
	return true;
}
