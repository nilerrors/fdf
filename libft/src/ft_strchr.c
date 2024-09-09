/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:32:07 by senayat           #+#    #+#             */
/*   Updated: 2024/07/17 00:36:24 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_str	ft_strchr(const t_str s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (t_byte)c)
			return ((t_str)(s + i));
		i++;
	}
	if (s[i] == (t_byte)c)
		return ((t_str)(s + i));
	return (NULL);
}
