#include "so_long.h"

int	ft_check_rows(t_map map)
{
	int	i;

	i = 0;
	while (i < map.rows)
	{
		if (map.full[i][0] != WALL)
			return ft_error_msg("wall missing form first row");
		else if (map.full[i][map.columns - 1] != WALL)
			return ft_error_msg("wall missing from last row");
		i++;
	}
	return true;
}

int	ft_check_columns(t_map map)
{
	int	i;

	i = 0;
	while (i < map.columns)
	{
		if (map.full[0][i] != WALL)
			return ft_error_msg("wall missing from fist col");
		else if (map.full[map.rows - 1][i] != WALL)
			return ft_error_msg("wall missing from last col");
		i++;
	}
	return true;
}

int	ft_count_map_parameters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				return ft_error_msg("unexpected character in map");
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == COINS)
				game->map.coins++;
			else if (game->map.full[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
	return true;
}

int	ft_verify_map_parameters(t_game *game)
{
	if (game->map.coins == 0)
		return ft_error_msg("no coins found");
	else if (game->map.exit == 0)
		return ft_error_msg("no exit found");
	else if (game->map.players != 1)
		return ft_error_msg("1 player required");
	else
		return true;
}

int	ft_check_map(t_game *game)
{
	return ft_check_rows(game->map) &&
	ft_check_columns(game->map) &&
	ft_count_map_parameters(game) &&
	ft_verify_map_parameters(game);
}
