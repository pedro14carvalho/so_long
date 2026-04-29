/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:23:31 by josepedr          #+#    #+#             */
/*   Updated: 2025/09/17 11:52:56 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	game_init(t_game *g)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (g->map.array[i] != '\n')
		i++;
	g->tiles_x = i;
	while (g->map.array[i])
	{
		if (g->map.array[i] == '\n')
			y++;
		i++;
	}
	g->tiles_y = y;
	g->height = y * 64;
	g->width = g->tiles_x * 64;
}

int	handle_input(int keysym, void *param)
{
	t_game	*g;

	g = param;
	if (keysym == XK_Escape)
		ft_close(g);
	if (keysym == XK_Down || keysym == 0x6a)
		player_down(g);
	if (keysym == XK_Up || keysym == 0x6b)
		player_up(g);
	if (keysym == XK_Left || keysym == 0x68)
		player_left(g);
	if (keysym == XK_Right || keysym == 0x6c)
		player_right(g);
	mlx_clear_window(g->vars.mlx, g->vars.win);
	fill_map(g);
	return (0);
}

void	init_player(t_game *g)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (g->map.array[i] != 'P')
	{
		if (g->map.array[i] == '\n')
		{
			x = 0;
			y++;
		}
		else
			x++;
		i++;
	}
	g->player.x = x;
	g->player.y = y;
}

void	mlx_start(t_game *g)
{
	g->vars.mlx = mlx_init();
	if (!g->vars.mlx)
	{
		ft_printf("Failed to allocate memory");
		free_map(g);
		exit(1);
	}
	g->vars.win = mlx_new_window(g->vars.mlx, g->width, g->height,
			"Pigs' Bay");
	if (!g->vars.win)
	{
		ft_printf("Failed to allocate memory");
		free_map(g);
		mlx_destroy_display(g->vars.mlx);
		free(g->vars.mlx);
		exit(1);
	}
}
