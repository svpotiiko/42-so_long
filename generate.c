/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:24:49 by vpotiiko          #+#    #+#             */
/*   Updated: 2023/02/16 13:55:06 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_length(t_game *vars)
//finds the leng of the map
{
	int		x;

	x = 0;
	while (vars->map[0][x])
		x++;
	return ((x + 4) * 32);
}

int	find_height(t_game *vars)
//finds the height of the map
{
	int		y;

	y = 0;
	while (vars->map[y])
		y++;
	return ((y + 4) * 32);
}

void	place_floor(t_game vars)
//places the bachground/grass on the map
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;

	x = 0;
	y = 0;
	max_x = find_length(&vars);
	max_y = find_height(&vars);
	while (y < max_y)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.background, x, y);
		while (x < max_x - 32)
		{
			x += 32;
			mlx_put_image_to_window(vars.mlx, vars.win, vars.background, x, y);
		}
		x = 0;
		y += 32;
	}
}

void	create_block(t_game *vars)
//creates a block by restricitng movement of the character
{
	if (vars->kitty_x == vars->x - 32 && vars->kitty_y == vars->y)
		vars->pass_right = 0;
	if (vars->kitty_x == vars->x + 32 && vars->kitty_y == vars->y)
		vars->pass_left = 0;
	if (vars->kitty_x == vars->x && vars->kitty_y == vars->y - 32)
		vars->pass_down = 0;
	if (vars->kitty_x == vars->x && vars->kitty_y == vars->y + 32)
		vars->pass_up = 0;
}

void	generate(t_game *vars)
//generates the window
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx,
			find_length(vars), find_height(vars), "so_long");
	vars->background = mlx_xpm_file_to_image(vars->mlx,
			"images/back.xpm", &vars->size, &vars->size);
	vars->bush = mlx_xpm_file_to_image(vars->mlx,
			"images/bush.xpm", &vars->size, &vars->size);
	vars->sweet = mlx_xpm_file_to_image(vars->mlx,
			"images/sweet.xpm", &vars->size, &vars->size);
	vars->kitty = mlx_xpm_file_to_image(vars->mlx,
			"images/char.xpm", &vars->size, &vars->size);
	vars->portal = mlx_xpm_file_to_image(vars->mlx,
			"images/exit.xpm", &vars->size, &vars->size);
	count_sweet(vars);
	place_floor(*vars);
	if (!check_map(vars))
		return_error_map(vars);
	if (!check_valid_path(vars))
		return_error_map(vars);
	free_map(vars);
	create_buf(vars);
	read_map(vars);
}
