/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:04:52 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 15:41:20 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "../../libft.h"

static void	ft_putfmt(t_fd fd, va_list *args, char f, size_t *n)
{
	if (f == '%')
		*n += ft_putc(fd, '%');
	else if (f == 'c')
		*n += ft_putc(fd, va_arg(*args, int));
	else if (f == 's')
		*n += ft_puts(fd, va_arg(*args, t_str));
	else if (f == 'p')
		*n += ft_putp(fd, va_arg(*args, t_data));
	else if (f == 'd' || f == 'i')
		*n += ft_putd(fd, va_arg(*args, int));
	else if (f == 'f')
		*n += ft_putf(fd, va_arg(*args, double));
	else if (f == 'u')
		*n += ft_putu(fd, va_arg(*args, t_uint));
	else if (f == 'x' || f == 'X')
		*n += ft_putx(fd, va_arg(*args, t_uint), f);
	else
		(*n)--;
}

static void	ft_fmt(t_fd fd, va_list *args, const t_str s, size_t *n)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_putfmt(fd, args, s[i], n);
		}
		else
			*n += ft_putc(fd, s[i]);
		i++;
	}
}

int	ft_printf(const t_str s, ...)
{
	size_t	n;
	va_list	args;

	n = 0;
	va_start(args, s);
	ft_fmt(FD_STDOUT, &args, s, &n);
	va_end(args);
	return (n);
}

int	ft_printerr(const t_str s, ...)
{
	size_t	n;
	va_list	args;

	n = 0;
	va_start(args, s);
	ft_fmt(FD_STDERR, &args, s, &n);
	va_end(args);
	return (n);
}

int	ft_printfd(t_fd fd, const t_str s, ...)
{
	size_t	n;
	va_list	args;

	n = 0;
	va_start(args, s);
	ft_fmt(fd, &args, s, &n);
	va_end(args);
	return (n);
}
