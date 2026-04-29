/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:39:09 by josepedr          #+#    #+#             */
/*   Updated: 2025/09/17 13:34:39 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	map_init(t_game *g)
{
	int		fd;
	char	*line;
	char	*tmp;

	g->map.array = ft_strdup("");
	fd = open(g->map.path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Unable to locate %s\n", g->map.path);
		free(g->map.path);
		free(g->map.array);
		exit(0);
	}
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(g->map.array, line);
		free(g->map.array);
		free(line);
		g->map.array = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	collectable_init(g);
}

static void	draw_edge_wall(t_game *g, int x, int y)
{
	if (y == 0)
	{
		if (x == 0)
			mlx_put_image_to_window(g->vars.mlx, g->vars.win,
				g->img.corner_left, x * 64, y * 64);
		else if (x == g->tiles_x - 1)
			mlx_put_image_to_window(g->vars.mlx, g->vars.win,
				g->img.corner_right, x * 64, y * 64);
		else
			mlx_put_image_to_window(g->vars.mlx, g->vars.win,
				g->img.up, x * 64, y * 64);
	}
	else if (y == g->tiles_y - 1)
	{
		if (x == 0)
			mlx_put_image_to_window(g->vars.mlx, g->vars.win,
				g->img.sand_left, x * 64, y * 64);
		else if (x == g->tiles_x - 1)
			mlx_put_image_to_window(g->vars.mlx, g->vars.win,
				g->img.sand_right, x * 64, y * 64);
		else
			mlx_put_image_to_window(g->vars.mlx, g->vars.win,
				g->img.beach, x * 64, y * 64);
	}
}

static void	draw_wall(t_game *g, int x, int y)
{
	if (y == 0 || y == g->tiles_y - 1)
		draw_edge_wall(g, x, y);
	else if (x == 0)
		mlx_put_image_to_window(g->vars.mlx, g->vars.win,
			g->img.left, x * 64, y * 64);
	else if (x == g->tiles_x - 1)
		mlx_put_image_to_window(g->vars.mlx, g->vars.win,
			g->img.right, x * 64, y * 64);
	else
		mlx_put_image_to_window(g->vars.mlx, g->vars.win,
			g->img.wall, x * 64, y * 64);
}

static void	draw_tile(t_game *g, int i, int x, int y)
{
	if (g->map.array[i] == '1')
		draw_wall(g, x, y);
	else if (g->map.array[i] == '0')
		mlx_put_image_to_window(g->vars.mlx, g->vars.win,
			g->img.water, x * 64, y * 64);
	else if (g->map.array[i] == 'P')
		mlx_put_image_to_window(g->vars.mlx, g->vars.win,
			g->img.player, x * 64, y * 64);
	else if (g->map.array[i] == 'C')
		randomize_collectable(g, i, x, y);
	else if (g->map.array[i] == 'E')
		mlx_put_image_to_window(g->vars.mlx, g->vars.win,
			g->img.exit, x * 64, y * 64);
}

void	fill_map(t_game *g)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (g->map.array[i])
	{
		if (g->map.array[i] == '\n')
		{
			y++;
			x = 0;
		}
		else
		{
			draw_tile(g, i, x, y);
			x++;
		}
		i++;
	}
}
