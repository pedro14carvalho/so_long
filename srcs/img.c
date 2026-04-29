/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:39:09 by josepedr          #+#    #+#             */
/*   Updated: 2025/09/23 17:23:06 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	*load_xpm(t_game *g, char *path)
{
	int		size;
	void	*img;

	img = mlx_xpm_file_to_image(g->vars.mlx, path, &size, &size);
	if (!img)
	{
		ft_printf("Error: Failed to load XPM file '%s'\n", path);
		exit(1);
	}
	return (img);
}

void	xpm_to_image(t_game *g)
{
	g->img.beach = load_xpm(g, "textures/beach.xpm");
	g->img.corner_left = load_xpm(g, "textures/corner_left.xpm");
	g->img.corner_right = load_xpm(g, "textures/corner_right.xpm");
	g->img.right = load_xpm(g, "textures/right.xpm");
	g->img.left = load_xpm(g, "textures/left.xpm");
	g->img.sand_left = load_xpm(g, "textures/sand_left.xpm");
	g->img.sand_right = load_xpm(g, "textures/sand_right.xpm");
	g->img.up = load_xpm(g, "textures/up.xpm");
	g->img.water = load_xpm(g, "textures/water.xpm");
	g->img.player = load_xpm(g, "textures/player_R.xpm");
	g->img.wall = load_xpm(g, "textures/wall.xpm");
	g->img.trash_1 = load_xpm(g, "textures/trash_1.xpm");
	g->img.trash_2 = load_xpm(g, "textures/trash_2.xpm");
	g->img.trash_3 = load_xpm(g, "textures/trash_3.xpm");
	g->img.exit = load_xpm(g, "textures/lighthouse_0.xpm");
}

void	free_images(t_game *g)
{
	mlx_destroy_image(g->vars.mlx, g->img.water);
	mlx_destroy_image(g->vars.mlx, g->img.player);
	mlx_destroy_image(g->vars.mlx, g->img.wall);
	mlx_destroy_image(g->vars.mlx, g->img.trash_1);
	mlx_destroy_image(g->vars.mlx, g->img.trash_2);
	mlx_destroy_image(g->vars.mlx, g->img.trash_3);
	mlx_destroy_image(g->vars.mlx, g->img.exit);
	mlx_destroy_image(g->vars.mlx, g->img.beach);
	mlx_destroy_image(g->vars.mlx, g->img.corner_left);
	mlx_destroy_image(g->vars.mlx, g->img.corner_right);
	mlx_destroy_image(g->vars.mlx, g->img.right);
	mlx_destroy_image(g->vars.mlx, g->img.left);
	mlx_destroy_image(g->vars.mlx, g->img.sand_left);
	mlx_destroy_image(g->vars.mlx, g->img.sand_right);
	mlx_destroy_image(g->vars.mlx, g->img.up);
}
