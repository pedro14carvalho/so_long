/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:25:21 by josepedr          #+#    #+#             */
/*   Updated: 2025/09/16 19:26:22 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	movement_counter(void)
{
	static int	counter;

	counter++;
	ft_printf("Total Moves: %d\n", counter);
	return (counter);
}

void	player_down(t_game *g)
{
	int	stride;
	int	start;
	int	dest;

	stride = g->tiles_x + 1;
	start = g->player.y * stride + g->player.x;
	dest = start + stride;
	if (g->map.array[dest] == '0' || g->map.array[dest] == 'C')
	{
		movement_counter();
		if (g->map.array[dest] == 'C')
			collectable_counter(g);
		g->map.array[dest] = 'P';
		g->map.array[start] = '0';
		g->player.y++;
	}
	if (g->map.array[dest] == 'E' && (collectable_check(g)))
		game_end(g);
}

void	player_up(t_game *g)
{
	int	stride;
	int	start;
	int	dest;

	stride = g->tiles_x + 1;
	start = g->player.y * stride + g->player.x;
	dest = start - stride;
	if (g->map.array[dest] == '0' || g->map.array[dest] == 'C')
	{
		movement_counter();
		if (g->map.array[dest] == 'C')
			collectable_counter(g);
		g->map.array[dest] = 'P';
		g->map.array[start] = '0';
		g->player.y--;
	}
	if (g->map.array[dest] == 'E' && (collectable_check(g)))
		game_end(g);
}

void	player_left(t_game *g)
{
	int	size;
	int	start;
	int	dest;

	size = 64;
	start = 0;
	while (g->map.array[start] != 'P')
		start++;
	dest = start - 1;
	if (g->map.array[dest] == '0' || g->map.array[dest] == 'C')
	{
		movement_counter();
		if (g->map.array[dest] == 'C')
			collectable_counter(g);
		g->map.array[dest] = 'P';
		g->map.array[start] = '0';
		g->player.x--;
	}
	if (g->map.array[dest] == 'E' && (collectable_check(g)))
		game_end(g);
	mlx_destroy_image(g->vars.mlx, g->img.player);
	g->img.player = mlx_xpm_file_to_image(g->vars.mlx, "textures/player_L.xpm",
			&size, &size);
}

void	player_right(t_game *g)
{
	int	size;
	int	start;
	int	dest;

	size = 64;
	start = 0;
	while (g->map.array[start] != 'P')
		start++;
	dest = start + 1;
	if (g->map.array[dest] == '0' || g->map.array[dest] == 'C')
	{
		movement_counter();
		if (g->map.array[dest] == 'C')
			collectable_counter(g);
		g->map.array[dest] = 'P';
		g->map.array[start] = '0';
		g->player.x++;
	}
	collectable_check(g);
	if (g->map.array[dest] == 'E' && (collectable_check(g)))
		game_end(g);
	mlx_destroy_image(g->vars.mlx, g->img.player);
	g->img.player = mlx_xpm_file_to_image(g->vars.mlx, "textures/player_R.xpm",
			&size, &size);
}
