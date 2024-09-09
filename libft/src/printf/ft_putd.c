/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:55:05 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 16:14:43 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_putd(t_fd fd, int nbr)
{
	t_str	base;
	long	nb;
	char	c;
	size_t	n;

	n = 1;
	base = "0123456789";
	if (nbr < 0)
	{
		n++;
		write(fd, "-", 1);
		nb = - (long)nbr;
	}
	else
		nb = (long)nbr;
	if (nb > 9)
	{
		n += ft_putd(fd, nb / 10);
	}
	c = base[nb % 10];
	write(fd, &c, 1);
	return (n);
}

size_t	ft_putf(t_fd fd, float nbr)
{
	size_t	c;

	c = 0;
	if (nbr < 0 && nbr > -1)
		c += ft_putc(fd, '-');
	c += ft_putd(fd, (int)nbr);
	c += ft_putc(fd, '.');
	c += ft_putd(fd, extract_decimal_part(nbr));
	return (c);
}
