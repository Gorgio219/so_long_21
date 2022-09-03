/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:39:31 by pbomber           #+#    #+#             */
/*   Updated: 2022/03/13 14:34:27 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "mlx/mlx.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

// # define ESC 53
// # define UP_KEY 126
// # define DOWN_KEY 125
// # define RIGHT_KEY 124
// # define LEFT_KEY 123

# define W 13
# define S 1
# define A 0
# define D 2

typedef struct s_map
{
	int	morty;
	int	stone;
	int	exit;
	int	start;
	int	valid;
}	t_map;

typedef struct s_image
{
	void	*img;
	int		h;
	int		w;
}	t_image;

typedef struct s_textures
{
	t_image	space;
	t_image	stone;
	t_image	exit_a;
	t_image	exit_b;
	t_image	player;
	t_image	morty;
	int		tocollect;
}	t_textures;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	char		**map;
	int			x;
	int			y;
	int			h;
	int			w;
	t_textures	img;
}	t_info;

t_map	g_valider;
t_info	g_game;

void		checking_map(char *argv);
int			check_read_map(char *fline, int fd);
char		*valid_map_struct(char const *s, char const *set);
int			check_line_map(char *s0, char *s1);

void		get_map(char *path);
void		draw_map(void);

int			mouse(void);
int			key(int key, void *param);
void		put_image(t_image texture, int x, int y);
void		go_player(int key);

void		stop(int code);
void		free_map(int line);
void		game_over(void);

char		*get_next_line(int fd);
#endif