/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:27:45 by pbomber           #+#    #+#             */
/*   Updated: 2021/10/26 00:01:07 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isprint(int c)
{
	if (((c > 31) && (c < 127)) || ((c > 67) && (c < 91))
		|| ((c > 96) && (c < 123)))
		return (1);
	return (0);
}
