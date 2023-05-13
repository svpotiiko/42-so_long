/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:41:30 by vpotiiko          #+#    #+#             */
/*   Updated: 2023/02/16 13:58:56 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *vars)
{
	mlx_destroy_image(vars->mlx, vars->kitty);
	vars->kitty = mlx_xpm_file_to_image(vars->mlx,
			"images/char.xpm", &vars->size, &vars->size);
	vars->kitty_x -= vars->size;
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
}

void	move_right(t_game *vars)
{
	mlx_destroy_image(vars->mlx, vars->kitty);
	vars->kitty = mlx_xpm_file_to_image(vars->mlx,
			"images/char.xpm", &vars->size, &vars->size);
	vars->kitty_x += vars->size;
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
}

void	move_up(t_game *vars)
{
	mlx_destroy_image(vars->mlx, vars->kitty);
	vars->kitty = mlx_xpm_file_to_image(vars->mlx,
			"images/char.xpm", &vars->size, &vars->size);
	vars->kitty_y -= vars->size;
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
}

void	move_down(t_game *vars)
{
	mlx_destroy_image(vars->mlx, vars->kitty);
	vars->kitty = mlx_xpm_file_to_image(vars->mlx,
			"images/char.xpm", &vars->size, &vars->size);
	vars->kitty_y += vars->size;
	vars->steps++;
	ft_printf("Steps: %d\n", vars->steps);
}

int	pressed(int keycode, t_game *vars)
{
	if (keycode == 53)
		close_game(vars);
	if (keycode == 0 && vars->pass_left == 1)
		move_left(vars);
	if (keycode == 2 && vars->pass_right == 1)
		move_right(vars);
	if (keycode == 13 && vars->pass_up == 1)
		move_up(vars);
	if (keycode == 1 && vars->pass_down == 1)
		move_down(vars);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		render_next_frame(vars);
	return (0);
}
