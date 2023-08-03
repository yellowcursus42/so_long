/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skulkamt <skulkamt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:18:15 by skulkamt          #+#    #+#             */
/*   Updated: 2023/08/03 21:46:06 by skulkamt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *message)
{
	ft_printf(RED "Error:" GREY "%s\n" RESET, message);
	return (false);
}

int	load_sprite(void *mlx, char *path, t_image *sprite)
{
	sprite->xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite->width,
			&sprite->height);
	if (sprite->xpm_ptr == NULL)
		return (error_msg("Couldn't find a sprite. Does it exist?"));
	return (true);
}
