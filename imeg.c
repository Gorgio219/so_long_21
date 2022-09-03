/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imeg.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:39:11 by pbomber           #+#    #+#             */
/*   Updated: 2022/03/13 14:27:56 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(void)
{
	g_game.img.space.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/space.XPM", &g_game.img.space.h, &g_game.img.space.w);
	g_game.img.stone.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/stone.XPM", &g_game.img.stone.h, &g_game.img.stone.w);
	g_game.img.exit_a.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/exit_a.XPM", &g_game.img.exit_a.h, &g_game.img.exit_a.w);
	g_game.img.exit_b.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/exit_b.XPM", &g_game.img.exit_b.h, &g_game.img.exit_b.w);
	g_game.img.player.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/player.XPM", &g_game.img.player.h,
			&g_game.img.player.w);
	g_game.img.morty.img = mlx_xpm_file_to_image(g_game.mlx,
			"./images/morty.XPM", &g_game.img.morty.h,
			&g_game.img.morty.w);
}

void	get_map(char *path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	g_game.map = malloc(sizeof(char *) * (g_game.h + 1));
	while (i < g_game.h)
	{
		g_game.map[i] = ft_strdup(line);
		if (!g_game.map[i])
		{
			free_map(i);
			return ;
		}
		i++;
		line = get_next_line(fd);
	}
	g_game.map[i] = NULL;
}

void	put_image(t_image texture, int x, int y)
{
	static int	n;

	mlx_put_image_to_window(g_game.mlx, g_game.win, texture.img,
		x * 50, y * 50);
	if (texture.img == g_game.img.player.img)
	{
		g_game.x = x;
		g_game.y = y;
		printf("Mooves: %d\n", n);
		n++;
	}
}

void	draw_map(void)
{
	int		i;
	int		j;

	i = -1;
	init_textures();
	while (++i < g_game.h)
	{
		j = -1;
		while (++j < g_game.w)
		{
			if (g_game.map[i][j] == '1')
				put_image(g_game.img.stone, j, i);
			else if (g_game.map[i][j] == 'E')
				put_image(g_game.img.exit_b, j, i);
			else
				put_image(g_game.img.space, j, i);
			if (g_game.map[i][j] == 'C')
			{
				put_image(g_game.img.morty, j, i);
				g_game.img.tocollect++;
			}
			if (g_game.map[i][j] == 'P')
				put_image(g_game.img.player, j, i);
		}
	}
}
