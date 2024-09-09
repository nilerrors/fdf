/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:56:15 by senayat           #+#    #+#             */
/*   Updated: 2024/07/17 00:24:19 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_data	ft_cpylr(t_data dst, const t_data src, size_t len)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		*(t_bytes)(dst + i) = *(t_bytes)(src + i);
		i--;
	}
	return (dst);
}

static t_data	ft_cpyrl(t_data dst, const t_data src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(t_bytes)(dst + i) = *(t_bytes)(src + i);
		i++;
	}
	return (dst);
}

t_data	ft_memmove(t_data dst, const t_data src, size_t len)
{
	if (dst > src && dst - src < (int)len)
		return (ft_cpylr(dst, src, len));
	if (src > dst && src - dst < (int)len)
		return (ft_cpyrl(dst, src, len));
	ft_memcpy(dst, src, len);
	return (dst);
}
