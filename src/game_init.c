/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skulkamt <skulkamt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:17:53 by skulkamt          #+#    #+#             */
/*   Updated: 2023/08/03 21:42:24 by skulkamt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_init_vars(t_game *game)
{
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	game->map.columns = ft_strlen(game->map.full[0]) - 1;
	return (true);
}

int	game_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		return (error_msg("Couldn't find mlx pointer."));
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map.columns * IMG_WIDTH,
			game->map.rows * IMG_HEIGHT,
			"so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		return (error_msg("Couldn't create the Window."));
	}
	return (true);
}

int	game_load_spries(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	return (load_sprite(mlx, WALL_XPM, &game->wall) && load_sprite(mlx,
			FLOOR_XPM, &game->floor) && load_sprite(mlx, COINS_XPM,
			&game->coins) && load_sprite(mlx, PLAYER_FRONT_XPM, &game->player)
		&& load_sprite(mlx, OPEN_EXIT_XPM, &game->exit_open) && load_sprite(mlx,
			EXIT_CLOSED_XPM, &game->exit_closed));
}
