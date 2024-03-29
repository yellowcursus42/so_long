/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skulkamt <skulkamt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:18:12 by skulkamt          #+#    #+#             */
/*   Updated: 2023/08/04 10:40:08 by skulkamt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>

# define IMG_HEIGHT 32
# define IMG_WIDTH 32

# define WALL 49
# define FLOOR 48
# define COINS 67
# define PLAYER 80
# define MAP_EXIT 69

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_Q 113
# define KEY_ESC 65307

# define WALL_XPM "assets/sprites/wall.xpm"
# define FLOOR_XPM "assets/sprites/floor.xpm"
# define COINS_XPM "assets/sprites/bone.xpm"
# define PLAYER_FRONT_XPM "assets/sprites/player.xpm"
# define EXIT_OPEN_XPM "assets/sprites/exit-open.xpm"
# define EXIT_CLOSED_XPM "assets/sprites/exit-closed.xpm"

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"

typedef enum e_bool
{
	false,
	true
}				t_bool;

typedef struct s_position
{
	int			x;
	int			y;
}				t_positon;

typedef struct s_image
{
	void		*xpm_ptr;
	int			width;
	int			height;
}				t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
}				t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	t_map		map;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		exit_open;
	t_image		exit_closed;
	t_image		player;
}				t_game;

int				cli_arg_check(int argc, char **argv);
void			free_game(t_game *game);
int				game_init_vars(t_game *game);
int				game_init_mlx(t_game *game);
int				game_load_spries(t_game *game);
int				handle_close_user(t_game *game);
int				handle_close_win(t_game *game);
int				handle_input(int keysym, t_game *game);
int				map_check(t_map *map);
int				map_init(t_map *map, char *map_path);
int				map_count_params(t_map *map);
int				render_map(t_game *game);
int				load_sprite(void *mlx, char *path, t_image *sprite);
int				error_msg(char *message);
#endif
