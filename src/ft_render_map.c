#include "so_long.h"

t_image	ft_identify_sprite(t_game *game, int y, int x)
{	
	char	parameter;

	parameter = game->map.full[y][x];
	if (parameter == WALL)
		return game->wall;
	else if (parameter == FLOOR)
		return game->floor;
	else if (parameter == COINS)
		return game->coins;
	else if (parameter == PLAYER)
		return game->player;
	else if (parameter == MAP_EXIT)
	{
		if (game->map.coins == 0)
			return game->open_exit;
		else
			return game->exit_closed;
	}
	else
		return game->floor;
}


void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
	sprite.xpm_ptr, column * sprite.width, line * sprite.height);
}

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movements : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			t_image sprite = ft_identify_sprite(game, y, x);
			ft_render_sprite(game, sprite, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}
