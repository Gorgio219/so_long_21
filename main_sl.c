/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:39:17 by pbomber           #+#    #+#             */
/*   Updated: 2022/03/13 14:14:41 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	checking_map(argv[1]);
	get_map(argv[1]);
	g_game.mlx = mlx_init();
	g_game.win = mlx_new_window(g_game.mlx, g_game.w * 50,
			g_game.h * 50, "so_long");
	draw_map();
	mlx_hook(g_game.win, 2, 0, key, 0);
	mlx_hook(g_game.win, 17, 0, mouse, 0);
	mlx_loop(g_game.mlx);
	return (0);
}
