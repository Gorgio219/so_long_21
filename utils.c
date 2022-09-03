/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:39:21 by pbomber           #+#    #+#             */
/*   Updated: 2022/03/13 14:12:05 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stop(int code)
{
	if (code)
		printf("Error\n");
	exit(code);
}

void	free_map(int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(g_game.map[i]);
		i++;
	}
	free(g_game.map);
}

void	game_over(void)
{
	free_map(g_game.h);
	mlx_destroy_image(g_game.mlx, g_game.img.space.img);
	mlx_destroy_image(g_game.mlx, g_game.img.stone.img);
	mlx_destroy_image(g_game.mlx, g_game.img.exit_a.img);
	mlx_destroy_image(g_game.mlx, g_game.img.exit_b.img);
	mlx_destroy_image(g_game.mlx, g_game.img.player.img);
	mlx_destroy_image(g_game.mlx, g_game.img.morty.img);
	mlx_destroy_window(g_game.mlx, g_game.win);
	stop(0);
}
