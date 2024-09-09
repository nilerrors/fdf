/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:01:00 by senayat           #+#    #+#             */
/*   Updated: 2024/08/07 12:30:50 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_putx(t_fd fd, t_uint n, char f)
{
	t_str	base;
	t_uint	num;
	size_t	i;

	if (f == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	num = n;
	if (num > 15)
		i += ft_putx(fd, num / 16, f);
	i += ft_putc(fd, base[num % 16]);
	return (i);
}
