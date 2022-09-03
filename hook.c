/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:38:57 by pbomber           #+#    #+#             */
/*   Updated: 2022/03/13 14:35:37 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse(void)
{
	game_over();
	return (0);
}

int	key(int key, void *param)
{
	(void)param;
	if (key == 53)
		game_over();
	if (key == 13 || key == 1 || key == 0 || key == 2)
		go_player(key);
	return (0);
}

void	open_exit(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_game.h)
	{
		j = 0;
		while (j < g_game.w)
		{
			if (g_game.map[i][j] == 'E')
				put_image(g_game.img.exit_a, j, i);
			j++;
		}
		i++;
	}
}

int	check_path(int dx, int dy)
{
	if (g_game.map[g_game.y + dy][g_game.x + dx] == 'C')
	{
		g_game.img.tocollect--;
		g_game.map[g_game.y + dy][g_game.x + dx] = '0';
	}
	if (!g_game.img.tocollect)
		open_exit();
	if (g_game.map[g_game.y + dy][g_game.x + dx] == '1')
		return (0);
	if (g_game.map[g_game.y + dy][g_game.x + dx] == 'E'
		&& g_game.img.tocollect)
		return (0);
	if (g_game.map[g_game.y + dy][g_game.x + dx] == 'E'
		&& !g_game.img.tocollect)
	{
		put_image(g_game.img.player, g_game.x + dx, g_game.y + dy);
		game_over();
	}
	return (1);
}

void	go_player(int key)
{
	if (key == 13 && check_path(0, -1))
	{
		put_image(g_game.img.space, g_game.x, g_game.y);
		put_image(g_game.img.player, g_game.x, g_game.y - 1);
	}
	if (key == 0 && check_path(-1, 0))
	{
		put_image(g_game.img.space, g_game.x, g_game.y);
		put_image(g_game.img.player, g_game.x - 1, g_game.y);
	}
	if (key == 1 && check_path(0, 1))
	{
		put_image(g_game.img.space, g_game.x, g_game.y);
		put_image(g_game.img.player, g_game.x, g_game.y + 1);
	}
	if (key == 2 && check_path(1, 0))
	{
		put_image(g_game.img.space, g_game.x, g_game.y);
		put_image(g_game.img.player, g_game.x + 1, g_game.y);
	}	
}
