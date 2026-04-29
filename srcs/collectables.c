/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectables.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:25:21 by josepedr          #+#    #+#             */
/*   Updated: 2025/09/17 12:07:33 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	collectable_check(t_game *g)
{
	int	i;

	i = 0;
	while (g->map.array[i])
	{
		if (g->map.array[i] == 'C')
			return (0);
		i++;
	}
	return (1);
}

void	collectable_counter(t_game *g)
{
	int			size;
	static int	counter;
	int			remaining;
	int			i;

	size = 64;
	i = 0;
	remaining = -1;
	while (g->map.array[i])
	{
		if (g->map.array[i] == 'C')
			remaining++;
		i++;
	}
	counter++;
	if (remaining)
		ft_printf("You've collected %d pieces of trash. %d remaining!\n",
			counter, remaining);
	else
	{
		ft_printf("You've collected all the trash! Go for the lighthouse!\n");
		mlx_destroy_image(g->vars.mlx, g->img.exit);
		g->img.exit = mlx_xpm_file_to_image(g->vars.mlx,
				"textures/lighthouse_1.xpm", &size, &size);
	}
}

void	collectable_init(t_game *g)
{
	int		i;
	char	j;

	i = 0;
	j = 'a';
	g->map.col_array = malloc(sizeof(int) * ft_strlen(g->map.array));
	if (!g->map.col_array)
		return ;
	while (g->map.array[i])
	{
		if (j == 'd')
			j = 'a';
		if (g->map.array[i] == 'C')
		{
			g->map.col_array[i] = j;
			j++;
		}
		else
			g->map.col_array[i] = '0';
		i++;
	}
}

void	randomize_collectable(t_game *g, int i, int x, int y)
{
	if (g->map.col_array[i] == 'a')
		mlx_put_image_to_window(g->vars.mlx, g->vars.win, g->img.trash_1,
			x * 64, y * 64);
	else if (g->map.col_array[i] == 'b')
		mlx_put_image_to_window(g->vars.mlx, g->vars.win, g->img.trash_2,
			x * 64, y * 64);
	else if (g->map.col_array[i] == 'c')
		mlx_put_image_to_window(g->vars.mlx, g->vars.win, g->img.trash_3,
			x * 64, y * 64);
}
