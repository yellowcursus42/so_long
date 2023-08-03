#include "so_long.h"

int	cli_arg_check(int argc, char **argv)
{
	if (argc > 2)
		return (error_msg("Only single argument required"));
	if (argc < 2)
		return (error_msg("Map file is missing."));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		return (error_msg("Invalid file extension (require .ber)."));
	return true;
}


int	map_init(t_map *map, char *map_path)
{
	char *map_temp;
	char *line_temp;
	int map_fd;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (error_msg("Can't open map file"));
	map_temp = ft_strdup("");
	map->rows = 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		char *appended = ft_strjoin(map_temp, line_temp);
		free(map_temp);
		free(line_temp);
		map_temp = appended;
		map->rows++;
	}
	close(map_fd);
	map->full = ft_split(map_temp, '\n');
	free(map_temp);
	return true;
}

