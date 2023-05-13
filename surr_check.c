/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surr_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:49:07 by vpotiiko          #+#    #+#             */
/*   Updated: 2023/02/16 14:10:52 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_vertic(t_game *vars)
//check that the vertical sides of the map are made up of '1's
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (vars->map[a])
	{
		if (vars->map[a][0] != '1')
			return (0);
		a++;
	}
	while (vars->map[0][b])
		b++;
	b--;
	a = 0;
	while (vars->map[a])
	{
		if (vars->map[a][b] != '1')
			return (0);
		a++;
	}
	return (1);
}

int	check_horiz(t_game *vars)
//check that the horizontal sides of the map are made up of '1's
{
	int	a;
	int	b;

	a = 1;
	b = -1;
	while (vars->map[a])
	{
		if (ft_strlen(vars->map[a - 1]) != ft_strlen(vars->map[a]))
			return (0);
		a++;
	}
	a--;
	while (vars->map[a][++b])
	{
		if (vars->map[a][b] != '1')
			return (0);
	}
	b = -1;
	while (vars->map[0][++b])
	{
		if (vars->map[0][b] != '1')
			return (0);
	}
	return (1);
}

int	count_element(t_game *vars, char c)
//counts the number of occurances of specified 'c' character in a map 
{
	int	a;
	int	b;
	int	n;

	a = 0;
	b = 0;
	n = 0;
	while (vars->map[a])
	{
		while (vars->map[a][b])
		{
			if (vars->map[a][b] != '0' && vars->map[a][b] != '1' &&
				vars->map[a][b] != 'C' && vars->map[a][b] != 'E' &&
				vars->map[a][b] != 'P')
				return (0);
			if (vars->map[a][b] == c)
				n++;
			b++;
		}
		b = 0;
		a++;
	}
	return (n);
}

int	check_map(t_game *vars)
//checks the map 
{
	int		i;
	int		j;
	int		portal;
	int		sweet;
	int		player;

	i = 0;
	j = 0;
	portal = count_element(vars, 'E');
	sweet = count_element(vars, 'C');
	player = count_element(vars, 'P');
	if (portal != 1 || player != 1 || sweet < 1)
		return (0);
	if (!check_vertic(vars))
		return (0);
	if (!check_horiz(vars))
		return (0);
	return (1);
}
