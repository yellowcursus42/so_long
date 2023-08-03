#include "so_long.h"

void	ft_destroy_images(t_game *game)
{
	if(game->wall.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	if(game->floor.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	if(game->coins.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->coins.xpm_ptr);
	if(game->player.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.xpm_ptr);
	if(game->exit_closed.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit_closed.xpm_ptr);
	if(game->open_exit.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->open_exit.xpm_ptr);
}

void	ft_free_map(t_game *game)
{
	int	string;

	string = 0;
	while (string < game->map.rows)
		free(game->map.full[string++]);
	free(game->map.full);
}

void	ft_free_all_allocated_memory(t_game *game)
{
	if(game->map.full)
		ft_free_map(game);
	if(game->mlx_ptr)
	{
		ft_destroy_images(game);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
}
