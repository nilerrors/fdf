/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:02:13 by senayat           #+#    #+#             */
/*   Updated: 2024/07/20 00:32:25 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const t_str s1, const t_str s2, size_t n)
{
	t_str	f;
	t_str	s;

	f = s1;
	s = s2;
	while (*s1 && *s1 == *s2 && n > 0)
	{
		f++;
		s++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(t_bytes)s1 - *(t_bytes)s2);
}
