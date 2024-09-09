/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:24:20 by senayat           #+#    #+#             */
/*   Updated: 2024/07/20 00:34:26 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_str	ft_strrchr(const t_str s, int c)
{
	size_t	i;
	t_str	last;

	last = (t_str)s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == (t_byte)c)
			return (last + i);
		i--;
	}
	if (last[i] == (t_byte)c)
		return (last);
	return (NULL);
}
