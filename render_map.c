/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:20:52 by vpotiiko          #+#    #+#             */
/*   Updated: 2023/02/18 16:34:56 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_sweet(t_game *vars, int n)
//similar to read map but does it during the game (movement)
{
	if (vars->kitty_x == vars->x && vars->kitty_y == vars->y)
	{
		vars->eda[n] = -1;
		vars->sweet_num--;
	}
	else
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sweet, vars->x, vars->y);
}

void	render_things(t_game *vars, int i, int j, int n)
{
	if (vars->map[i][j] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->bush, vars->x, vars->y);
		create_block(vars);
	}
	if (vars->map[i][j] == 'E')
	{
		if (vars->sweet_num > 0)
			create_block(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->portal, vars->x, vars->y);
		if (vars->kitty_x == vars->x && vars->kitty_y == vars->y)
			win_game(vars);
	}
	if (vars->map[i][j] == 'C' && vars->eda[n] == 1)
		render_sweet(vars, n);
}

void	read_map_new(t_game *vars)
//also counts number of collectabes collected
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = 0;
	while (vars->map[i])
	{
		while (vars->map[i][j])
		{
			render_things(vars, i, j, n);
			if (vars->map[i][j] == 'C')
				n++;
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
