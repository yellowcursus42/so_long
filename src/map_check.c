#include "so_long.h"

int	map_check_rows(t_map map)
{
	int	i;

	i = 0;
	while (i < map.rows)
	{
		if (map.full[i][0] != WALL)
			return error_msg("wall missing form first row");
		else if (map.full[i][map.columns - 1] != WALL)
			return error_msg("wall missing from last row");
		i++;
	}
	return true;
}

int	map_check_columns(t_map map)
{
	int	i;

	i = 0;
	while (i < map.columns)
	{
		if (map.full[0][i] != WALL)
			return error_msg("wall missing from fist col");
		else if (map.full[map.rows - 1][i] != WALL)
			return error_msg("wall missing from last col");
		i++;
	}
	return true;
}

int	map_validate_params(t_map map)
{
	if (map.coins == 0)
		return error_msg("no coins found");
	else if (map.exit == 0)
		return error_msg("no exit found");
	else if (map.players != 1)
		return error_msg("1 player required");
	else
		return true;
}

int	map_count_params(t_map * map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if (!ft_strchr("CEP01", map->full[y][x]))
				return error_msg("unexpected character in map");
			else if (map->full[y][x] == PLAYER)
			{
				map->players++;
				map->player.x = x;
				map->player.y = y;
			}
			else if (map->full[y][x] == COINS)
				map->coins++;
			else if (map->full[y][x] == MAP_EXIT)
				map->exit++;
			x++;
		}
		y++;
	}
	return true;
}

int map_check_emptyline(t_map map){
	
	int	i;

	i = 0;
	while (i < map.rows)
	{
		if (ft_strlen( map.full[i] ) <= 1)
			return error_msg("empty line in between.");
		i++;
	}
	return true;
}

int	map_check(t_map *map)
{
	return map_check_emptyline(*map)&&
		map_check_rows(*map) &&
	map_check_columns(*map) &&
	map_count_params(map) &&
	map_validate_params(*map);
}
