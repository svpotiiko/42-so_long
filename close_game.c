/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:20:05 by vpotiiko          #+#    #+#             */
/*   Updated: 2023/02/16 13:53:15 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *vars)
//frees map to avoid memory leaks
{
	int		a;

	a = 0;
	while (vars->map[a])
	{
		free(vars->map[a]);
		a++;
	}
	free(vars->map);
}

int	close_game(t_game *vars)
//closes the game if esc is pressed
{
	mlx_destroy_image(vars->mlx, vars->background);
	mlx_destroy_image(vars->mlx, vars->sweet);
	mlx_destroy_image(vars->mlx, vars->bush);
	mlx_destroy_image(vars->mlx, vars->portal);
	mlx_destroy_image(vars->mlx, vars->kitty);
	free_map(vars);
	free(vars->eda);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	ft_printf("Game closed\n");
	exit(0);
}

int	win_game(t_game *vars)
//closes the game in case of a victory
{
	mlx_destroy_image(vars->mlx, vars->background);
	mlx_destroy_image(vars->mlx, vars->sweet);
	mlx_destroy_image(vars->mlx, vars->bush);
	mlx_destroy_image(vars->mlx, vars->portal);
	mlx_destroy_image(vars->mlx, vars->kitty);
	free_map(vars);
	free(vars->eda);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	ft_printf("You won:)\n");
	exit(0);
}
