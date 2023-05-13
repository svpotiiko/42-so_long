/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:28:11 by vpotiiko          #+#    #+#             */
/*   Updated: 2023/02/16 14:06:42 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	return_error(void)
//returns an error
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid argument\n", 2);
	exit(1);
}

void	return_error_map(t_game *vars)
//error in case of an invalid map
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
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid map\n", 2);
	exit(1);
}
