/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:39:00 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 19:55:18 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	ft_strendswith(t_str s, t_str end)
{
	t_uint	s_len;
	t_uint	end_len;

	s_len = ft_strlen(s);
	end_len = ft_strlen(end);
	if (end_len > s_len)
		return (FALSE);
	return (ft_strncmp(s + (s_len - end_len), end, end_len) == 0);
}
