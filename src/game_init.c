#include "so_long.h"

int	ft_init_vars(t_game *game)
{
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	game->map.columns = ft_strlen(game->map.full[0]) - 1;
	return true;
}

int	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		return ft_error_msg("Couldn't find mlx pointer.");
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		return ft_error_msg("Couldn't create the Window.");
	}
	return true;
}

int	ft_new_sprite(void *mlx, char *path, t_image *sprite)
{
	sprite->xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite->width, &sprite->height);
	if (sprite->xpm_ptr == NULL)
		return ft_error_msg("Couldn't find a sprite. Does it exist?");
	return true;
}

int	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	return ft_new_sprite(mlx, WALL_XPM,&game->wall ) &&
	ft_new_sprite(mlx, FLOOR_XPM,&game->floor ) &&
	ft_new_sprite(mlx, COINS_XPM,&game->coins ) &&
	ft_new_sprite(mlx, PLAYER_FRONT_XPM,&game->player ) &&
	ft_new_sprite(mlx, OPEN_EXIT_XPM,&game->open_exit ) &&
	ft_new_sprite(mlx, EXIT_CLOSED_XPM,&game->exit_closed );
}
