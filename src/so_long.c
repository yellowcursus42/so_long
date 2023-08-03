#include "so_long.h"

int	main(int argc, char	**argv)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	if(cli_arg_check(argc, argv) &&
	map_init(&game->map, argv[1]) &&
	game_init_vars(game) &&
	map_check(&game->map) &&
	game_init_mlx(game) &&
	game_load_spries(game)){
		ft_printf("game started\n");
		render_map(game);
		mlx_hook(game->win_ptr, KeyPress, KeyPressMask, handle_input, game);
		mlx_hook(game->win_ptr, DestroyNotify, ButtonPressMask, handle_close_user, game);
		mlx_hook(game->win_ptr, Expose, ExposureMask, render_map, game);
		mlx_loop(game->mlx_ptr);
	}
	else{
		free_game(game);
		return EXIT_FAILURE;
	}
}
