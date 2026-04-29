/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:25:21 by josepedr          #+#    #+#             */
/*   Updated: 2025/09/17 12:09:14 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	map_check(t_game *g)
{
	if (!is_shape_valid(g))
	{
		ft_printf("Error: Map is not a valid shape\n");
		return (0);
	}
	if (!is_surrounded_by_walls(g))
	{
		ft_printf("Error: Map should be surrounded by walls\n");
		return (0);
	}
	if (!map_content(g))
	{
		ft_printf("Error: Map must have 1 'P', 1 'E', and at least 1 'C'.\n");
		return (0);
	}
	return (1);
}

int	is_shape_valid(t_game *g)
{
	int	i;
	int	row_length;
	int	current_length;

	i = 0;
	row_length = 0;
	current_length = 0;
	while (g->map.array[i])
	{
		if (g->map.array[i] == '\n')
		{
			if (!row_length)
				row_length = current_length;
			else if (current_length != row_length)
				return (0);
			current_length = 0;
		}
		else
			current_length++;
		i++;
	}
	if (current_length != row_length && current_length > 0)
		return (0);
	return (1);
}

int	is_surrounded_by_walls(t_game *g)
{
	int	i;
	int	stride;

	i = 0;
	stride = g->tiles_x + 1;
	while (i < g->tiles_x)
	{
		if (g->map.array[i] != '1'
			|| g->map.array[(g->tiles_y - 1) * stride + i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < g->tiles_y)
	{
		if (g->map.array[i * stride] != '1'
			|| g->map.array[i * stride + g->tiles_x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_content(t_game *g)
{
	int	i;
	int	player_count;
	int	exit_count;
	int	collectable_count;

	i = 0;
	player_count = 0;
	exit_count = 0;
	collectable_count = 0;
	while (g->map.array[i])
	{
		if (g->map.array[i] == 'P')
			player_count++;
		else if (g->map.array[i] == 'E')
			exit_count++;
		else if (g->map.array[i] == 'C')
			collectable_count++;
		else if (g->map.array[i] != '1' && g->map.array[i] != '0'
			&& g->map.array[i] != '\n')
			return (0);
		i++;
	}
	if (player_count != 1 || exit_count != 1 || collectable_count < 1)
		return (0);
	return (1);
}
