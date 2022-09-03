/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:38:49 by pbomber           #+#    #+#             */
/*   Updated: 2022/03/13 14:11:47 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*valid_map_struct(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 'E')
			g_valider.exit += 1;
		if (s[i] == 'C')
			g_valider.morty += 1;
		if (s[i] == 'P')
			g_valider.start += 1;
		if (s[i] == '1')
			g_valider.stone += 1;
		if (g_valider.exit > 0 && g_valider.morty > 0 && g_valider.start > 0
			&& g_valider.stone > 0)
			g_valider.valid = 1;
		i++;
	}
	return (ft_strtrim(s, set));
}

int	check_line_map(char *s0, char *s1)
{
	char	*tmp;
	int		flag;

	if (s0 == NULL)
		tmp = valid_map_struct(s1, "1");
	else if (s1 == NULL)
		tmp = valid_map_struct(s0, "1");
	else if (ft_strlen(s0) == ft_strlen(s1) && s1[0] == '1'
		&& s1[ft_strlen(s1) - 2] == '1')
		tmp = valid_map_struct(s1, "ECP01");
	else
		return (0);
	if (!ft_memcmp(tmp, "\n", 1) || !ft_memcmp(tmp, "\0", 1))
		flag = 1;
	else
		flag = 0;
	free(tmp);
	return (flag);
}

int	check_read_map(char *fline, int fd)
{
	char			*line;
	int				flag;

	flag = check_line_map(NULL, fline);
	line = get_next_line(fd);
	g_game.w = ft_strlen(fline) - 1;
	g_game.h += 1;
	while (line && flag)
	{
		flag = check_line_map(fline, line);
		free(fline);
		fline = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		g_game.h += 1;
	}
	if (!line && flag)
		flag = check_line_map(fline, NULL);
	free(line);
	free(fline);
	if (g_valider.start > 1)
		flag = 0;
	return (flag * g_valider.valid);
}

void	checking_map(char *argv)
{
	int		fd;
	char	*line;

	if (ft_strlen(argv) < 4 && ft_memcmp(*argv + (ft_strlen - 4), ".ber", 4))
		stop(1);
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		stop(1);
	if (!check_read_map(line, fd))
		stop(1);
}
