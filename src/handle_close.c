/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skulkamt <skulkamt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:17:56 by skulkamt          #+#    #+#             */
/*   Updated: 2023/08/03 21:42:24 by skulkamt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close_win(t_game *game)
{
	ft_printf(CYAN "Movements: %d\n" RESET, ++game->movements);
	ft_printf(GREEN "YOU WIN\n" RESET);
	exit(EXIT_SUCCESS);
}

int	handle_close_user(t_game *game)
{
	ft_printf(CYAN "Movements: %d\n" RESET, game->movements);
	ft_printf(GREY "CLOSED\n" RESET);
	exit(EXIT_SUCCESS);
}
