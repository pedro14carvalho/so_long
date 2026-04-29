/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:51:26 by josepedr          #+#    #+#             */
/*   Updated: 2025/09/17 12:14:58 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_close(t_game *g)
{
	free_images(g);
	mlx_destroy_window(g->vars.mlx, g->vars.win);
	mlx_destroy_display(g->vars.mlx);
	free(g->vars.mlx);
	ft_printf("Game exited before completion\n");
	free(g->map.path);
	free(g->map.array);
	free(g->map.col_array);
	exit(1);
}

void	game_end(t_game *g)
{
	int	total_moves;

	total_moves = movement_counter();
	free_images(g);
	mlx_destroy_window(g->vars.mlx, g->vars.win);
	mlx_destroy_display(g->vars.mlx);
	free(g->vars.mlx);
	ft_printf("YOU DID IT!\nThe beach is now LESS DIRTY and it only took");
	ft_printf(" you %d moves!\n", total_moves);
	free(g->map.path);
	free(g->map.array);
	free(g->map.col_array);
	exit(0);
}

int	handle_close(t_game *g)
{
	ft_close(g);
	return (0);
}

void	free_map(t_game *g)
{
	free(g->map.path);
	free(g->map.array);
	free(g->map.col_array);
}
