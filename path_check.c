/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:13:37 by vpotiiko          #+#    #+#             */
/*   Updated: 2023/02/16 14:04:03 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_game *vars)
//determines and saves coordinates of where the player is
{
	vars->x = 0;
	vars->y = 0;
	while (vars->map[vars->y])
	{
		while (vars->map[vars->y][vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'P')
				return ;
			vars->x++;
		}
		vars->x = 0;
		vars->y++;
	}
}

void	checking(t_game *vars, int y, int x)
//recursivly checks he walkable path by labaling stepped on place 'a'
{
	if (vars->map[y][x] == '1' &&
		vars->map[y][x] == 0)
		return ;
	if (vars->map[y][x] == 'C')
		vars->food_check++;
	if (vars->map[y][x] == 'E')
		vars->exit_check = 1;
	vars->map[y][x] = 'a';
	if (vars->map[y][x + 1] != '1' &&
		vars->map[y][x + 1] != 'a')
		checking(vars, y, x + 1);
	if (vars->map[y + 1][x] != '1' &&
		vars->map[y + 1][x] != 'a')
		checking(vars, y + 1, x);
	if (vars->map[y][x - 1] != '1' &&
		vars->map[y][x - 1] != 'a')
		checking(vars, y, x - 1);
	if (vars->map[y - 1][x] != '1' &&
		vars->map[y - 1][x] != 'a')
		checking(vars, y - 1, x);
}

int	check_valid_path(t_game *vars)
//complete path check
{
	vars->food_check = 0;
	vars->exit_check = 0;
	get_player_pos(vars);
	checking(vars, vars->y, vars->x);
	if ((vars->exit_check == 1) && (vars->food_check == vars->sweet_num))
		return (1);
	return (0);
}
