/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:12:36 by pbomber           #+#    #+#             */
/*   Updated: 2022/03/13 14:07:58 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*cut_str(char **s)
{
	char	*line;
	char	*tmp;

	if (search_n(*s) != -1)
	{
		line = ft_substr(*s, 0, search_n(*s) + 1);
		tmp = ft_substr(*s, search_n(*s) + 1, ft_strlen(*s));
		free(*s);
		*s = NULL;
		*s = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
	}	
	else
	{
		line = ft_substr(*s, 0, ft_strlen(*s));
		free(*s);
		*s = NULL;
	}
	return (line);
}

char	*back_str(char **ostat, char *buffer, int fd)
{
	int		how_much_bit;
	char	*str;

	if (search_n(*ostat) != -1)
		return (cut_str(ostat));
	how_much_bit = read(fd, buffer, 10);
	if (how_much_bit <= 0)
	{
		if (**ostat)
			return (cut_str(ostat));
		else
		{
			free(*ostat);
			*ostat = NULL;
			return (NULL);
		}
	}
	buffer[how_much_bit] = '\0';
	str = ft_strjoin(*ostat, buffer);
	free(*ostat);
	*ostat = NULL;
	*ostat = ft_strdup(str);
	free(str);
	str = NULL;
	return (back_str(ostat, buffer, fd));
}

char	*get_next_line(int fd)
{	
	static char	*ostat;
	char		*buffer;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || read(fd, NULL, 0) < 0 || 10 <= 0)
		return (NULL);
	buffer = (char *)malloc(10 + 1);
	if (!buffer)
		return (NULL);
	if (!ostat)
		ostat = ft_strdup("");
	line = back_str(&ostat, buffer, fd);
	free(buffer);
	buffer = NULL;
	return (line);
}
