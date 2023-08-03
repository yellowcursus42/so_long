/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skulkamt <skulkamt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:18:00 by skulkamt          #+#    #+#             */
/*   Updated: 2023/08/03 21:42:24 by skulkamt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(t_game *game, int new_y, int new_x)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.coins == 0)
		return (handle_close_win(game));
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
		render_map(game);
	}
	return (true);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		return (player_move(game, game->map.player.y - 1, game->map.player.x));
	if (keysym == KEY_LEFT || keysym == KEY_A)
		return (player_move(game, game->map.player.y, game->map.player.x - 1));
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		return (player_move(game, game->map.player.y, game->map.player.x + 1));
	if (keysym == KEY_DOWN || keysym == KEY_S)
		return (player_move(game, game->map.player.y + 1, game->map.player.x));
	if (keysym == KEY_Q || keysym == KEY_ESC)
		return (handle_close_user(game));
	return (true);
}
