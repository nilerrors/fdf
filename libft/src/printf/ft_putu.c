/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:05:03 by senayat           #+#    #+#             */
/*   Updated: 2024/08/07 12:30:28 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_putu(t_fd fd, t_uint n)
{
	size_t	len;
	t_str	base;

	len = 0;
	base = "0123456789";
	if (n > 9)
		len += ft_putu(fd, n / 10);
	len += ft_putc(fd, base[n % 10]);
	return (len);
}
