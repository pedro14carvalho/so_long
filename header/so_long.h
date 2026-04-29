/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:30:53 by josepedr          #+#    #+#             */
/*   Updated: 2025/09/17 11:53:41 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/keysym.h>

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*win;
}				t_mlx_vars;

typedef struct s_player
{
	int		x;
	int		y;
}				t_player;

typedef struct s_img
{
	void	*water;
	void	*wall;
	void	*player;
	void	*trash_1;
	void	*trash_2;
	void	*trash_3;
	void	*exit;
	void	*beach;
	void	*shark;
	void	*corner_left;
	void	*corner_right;
	void	*left;
	void	*right;
	void	*sand_left;
	void	*sand_right;
	void	*up;
}				t_img;

typedef struct s_map
{
	char	*path;
	char	*array;
	char	*col_array;
}				t_map;

typedef struct s_game
{
	int			height;
	int			width;
	int			tiles_x;
	int			tiles_y;
	t_mlx_vars	vars;
	t_player	player;
	t_map		map;
	t_img		img;
}				t_game;

//IMG.c	
void	free_images(t_game *g);
void	xpm_to_image(t_game *g);

//MAP.c
void	map_init(t_game *g);
void	fill_map(t_game *g);
void	randomize_collectable(t_game *g, int i, int x, int y);

//GAME.c
int		handle_input(int keysym, void *param);
void	init_player(t_game *g);
void	game_init(t_game *g);
void	mlx_start(t_game *g);

//MOVEMENT.c
int		movement_counter(void);
void	player_down(t_game *g);
void	player_up(t_game *g);
void	player_left(t_game *g);
void	player_right(t_game *g);

//COLLECTABLES.c
int		collectable_check(t_game *g);
void	collectable_counter(t_game *g);
void	collectable_init(t_game *g);

//MAP_CHECK.c
int		map_check(t_game *g);
int		is_shape_valid(t_game *g);
int		is_surrounded_by_walls(t_game *g);
int		map_content(t_game *g);

//CLOSE.c
int		handle_close(t_game *g);
void	game_end(t_game *g);
void	ft_close(t_game *g);
void	free_map(t_game *g);

#endif
