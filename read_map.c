/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:23:18 by vpotiiko          #+#    #+#             */
/*   Updated: 2023/02/18 16:41:23 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_sweet(t_game *vars)
//counts the number of collectables(sweets) on a map
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->map[y])
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
				vars->sweet_num++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	put_things(t_game *vars, int i, int j)
//puts components of the map to the window
{
	if (vars->map[i][j] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->bush, vars->x, vars->y);
		create_block(vars);
	}
	if (vars->map[i][j] == 'E')
	{
		create_block(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->portal, vars->x, vars->y);
	}
	if (vars->map[i][j] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sweet, vars->x, vars->y);
	}
	if (vars->map[i][j] == 'P')
	{
		vars->kitty_x = vars->x;
		vars->kitty_y = vars->y;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->kitty, vars->x, vars->y);
	}
}

void	read_map(t_game *vars)
//goes through the map and uses put_things function
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	vars->x = 64;
	vars->y = 64;
	while (vars->map[i])
	{
		while (vars->map[i][j])
		{
			put_things(vars, i, j);
			j++;
			vars->x += 32;
		}
		j = 0;
		i++;
		vars->x = 64;
		vars->y += 32;
	}
	vars->x = 64;
	vars->y = 64;
}
