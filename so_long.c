/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:53:56 by vpotiiko          #+#    #+#             */
/*   Updated: 2023/02/18 16:36:40 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkk(char	*str)
//checks that the map is a .ber file
{
	if (ft_strncmp(ft_strrchr(str, '.'), ".ber", 5) == 0)
		return (1);
	return (0);
}

int	render_next_frame(t_game *vars)
//renders the map
{
	mlx_clear_window(vars->mlx, vars->win);
	place_floor(*vars);
	vars->pass_left = 1;
	vars->pass_right = 1;
	vars->pass_up = 1;
	vars->pass_down = 1;
	read_map_new(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->kitty, vars->kitty_x, vars->kitty_y);
	return (0);
}

void	create_buf(t_game *vars)
//opens a file and saves to variable 
{
	char	*s;
	char	*str;
	int		fd;
	int		i;

	fd = open(vars->map_path, O_RDONLY);
	if (read(fd, 0, 0) < 0)
		return_error();
	str = ft_calloc(1, sizeof(char));
	s = ft_calloc(1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, s, 1);
		if (i > 0)
			str = ft_strjoin(str, s);
	}
	vars->map = ft_split(str, '\n');
	close(fd);
	free(s);
	free(str);
}

int	main(int argc, char	**argv)
{
	int		a;
	t_game	vars;

	if ((argc != 2) || !checkk(argv[1]))
		return_error();
	vars.map_path = argv[1];
	create_buf(&vars);
	vars.size = 32;
	vars.steps = 0;
	vars.sweet_num = 0;
	vars.pass_left = 1;
	vars.pass_right = 1;
	vars.pass_up = 1;
	vars.pass_down = 1;
	generate(&vars);
	a = 0;
	vars.eda = ft_calloc(sizeof(int), vars.sweet_num);
	while (a < vars.sweet_num)
		vars.eda[a++] = 1;
	ft_printf("Steps: %d\n", vars.steps);
	mlx_hook(vars.win, 2, 1L << 0, pressed, &vars);
	mlx_hook(vars.win, 17, 0, close_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
