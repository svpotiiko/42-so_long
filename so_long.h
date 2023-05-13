/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:28:18 by vpotiiko          #+#    #+#             */
/*   Updated: 2023/02/14 20:17:31 by vpotiiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct game {
	void	*mlx;
	void	*win;
	void	*kitty;
	void	*background;
	void	*bush;
	void	*portal;
	char	**map;
	char	*map_path;
	int		steps;
	int		size;
	int		x;
	int		y;
	int		kitty_x;
	int		kitty_y;
	int		pass_left;
	int		pass_right;
	int		pass_up;
	int		pass_down;
	int		sweet_num;
	int		food_check;
	int		exit_check;
	int		*eda;
	void	*sweet;
}				t_game;

int		find_length(t_game *vars);
int		find_height(t_game *vars);
int		pressed(int keycode, t_game *vars);
int		render_next_frame(t_game *vars);
void	place_floor(t_game vars);
void	create_block(t_game *vars);
void	put_things(t_game *vars, int i, int j);
void	read_map(t_game *vars);
void	create_buf(t_game *vars);
void	count_sweet(t_game *vars);
void	render_sweet(t_game *vars, int n);
void	render_things(t_game *vars, int i, int j, int n);
void	read_map_new(t_game *vars);
void	move_left(t_game *vars);
void	move_right(t_game *vars);
void	move_up(t_game *vars);
void	move_down(t_game *vars);
void	generate(t_game *vars);
void	free_map(t_game *vars);
int		close_game(t_game *vars);
int		win_game(t_game *vars);
void	get_player_pos(t_game *vars);
int		count_element(t_game *vars, char c);
int		check_map(t_game *vars);
void	return_error(void);
void	return_error_map(t_game *vars);
void	checking(t_game *vars, int y, int x);
int		check_valid_path(t_game *vars);
int		checkk(char	*str);

#endif