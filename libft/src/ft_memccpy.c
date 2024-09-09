/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:36:25 by senayat           #+#    #+#             */
/*   Updated: 2024/07/17 00:19:53 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_data	ft_memccpy(t_data dst, const t_data src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(t_bytes)(dst + i) = *(t_bytes)(src + i);
		if (*(t_bytes)(src + i) == (t_byte)c)
			return ((t_data)(dst + i + 1));
		i++;
	}
	return (NULL);
}
