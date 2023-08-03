#include "so_long.h"

int	main(int argc, char	**argv)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	if(ft_check_cli_args(argc, argv) &&
	ft_init_map(&game->map, argv[1]) &&
	ft_init_vars(game) &&
	ft_check_map(game) &&
	ft_init_mlx(game) &&
	ft_init_sprites(game)){
		ft_printf("game started\n");
		ft_render_map(game);
		mlx_hook(game->win_ptr, KeyPress, KeyPressMask, ft_handle_input, game);
		mlx_hook(game->win_ptr, DestroyNotify, ButtonPressMask, ft_close_by_user, game);
		mlx_hook(game->win_ptr, Expose, ExposureMask, ft_render_map, game);
		mlx_loop(game->mlx_ptr);
	}
	else{
		ft_free_all_allocated_memory(game);
		return EXIT_FAILURE;
	}
}
