/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josepedr <josepedr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:23:31 by josepedr          #+#    #+#             */
/*   Updated: 2025/09/17 12:13:39 by josepedr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(int ac, char **av)
{
	t_game	g;

	if (ac < 2)
	{
		ft_printf("Please provide the map you wish to play as an argument\n");
		exit(1);
	}
	g.map.path = ft_strjoin("maps/", av[1]);
	map_init(&g);
	game_init(&g);
	if (!map_check(&g))
	{
		free_map(&g);
		exit(1);
	}
	mlx_start(&g);
	mlx_key_hook(g.vars.win, handle_input, &g);
	mlx_hook(g.vars.win, 17, 0, handle_close, &g);
	xpm_to_image(&g);
	fill_map(&g);
	init_player(&g);
	mlx_loop(g.vars.mlx);
}
