/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:16:21 by senayat           #+#    #+#             */
/*   Updated: 2024/08/07 12:29:35 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	ft_putb(t_fd fd, t_ulong n)
{
	int	len;

	len = 0;
	if (n > 15)
		len += ft_putb(fd, n / 16);
	len += ft_putc(fd, "0123456789abcdef"[n % 16]);
	return (len);
}

size_t	ft_putp(t_fd fd, t_ptr addr)
{
	t_ulong	n;
	size_t	len;

	if (!addr)
		return (ft_puts(fd, "(nil)"));
	n = (t_ulong)addr;
	len = ft_puts(fd, "0x");
	len += ft_putb(fd, n);
	return (len);
}
