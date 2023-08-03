/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skulkamt <skulkamt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:18:02 by skulkamt          #+#    #+#             */
/*   Updated: 2023/08/03 21:45:08 by skulkamt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check_edges(t_map map)
{
	int	i;

	i = 0;
	while (i < map.rows)
	{
		if (map.full[i][0] != WALL)
			return (error_msg("wall missing form first row"));
		else if (map.full[i][map.columns - 1] != WALL)
			return (error_msg("wall missing from last row"));
		i++;
	}
	i = 0;
	while (i < map.columns)
	{
		if (map.full[0][i] != WALL)
			return (error_msg("wall missing from fist col"));
		else if (map.full[map.rows - 1][i] != WALL)
			return (error_msg("wall missing from last col"));
		i++;
	}
	return (true);
}

int	map_validate_params(t_map map)
{
	if (map.coins == 0)
		return (error_msg("no coins found"));
	else if (map.exit == 0)
		return (error_msg("no exit found"));
	else if (map.players != 1)
		return (error_msg("1 player required"));
	else
		return (true);
}

int	map_check(t_map *map)
{
	return (map_check_edges(*map)
		&& map_validate_params(*map));
}
