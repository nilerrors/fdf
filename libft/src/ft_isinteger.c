/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:23:19 by senayat           #+#    #+#             */
/*   Updated: 2024/07/17 00:32:41 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_bool	int_overflows(long long n)
{
	return ((n > INT_MAX) || (n < INT_MIN));
}

static void	skip_space(t_str *str)
{
	while (ft_isspace(**str))
		(*str)++;
}

static t_bool	handle_current_dig(t_str str, long long *res, t_bool isneg)
{
	int	dig;

	dig = (*str - '0');
	if ((isneg && (-*res < (LLONG_MIN + dig) / 10))
		|| (!isneg && (*res > (LLONG_MAX - dig) / 10)))
		return (FALSE);
	*res = (*res) * 10 + dig;
	return (TRUE);
}

t_bool	ft_isinteger(const t_str str, int *n)
{
	t_bool		isneg;
	long long	res;
	t_str		s;

	isneg = FALSE;
	res = 0;
	s = str;
	if (!s || *s == '\0')
		return (FALSE);
	skip_space(&s);
	if (*s == '+' || *s == '-')
		isneg = (*(s++) == '-');
	if (!ft_isdigit(*s))
		return (FALSE);
	while (ft_isdigit(*s))
		if (!handle_current_dig(s++, &res, isneg))
			return (FALSE);
	skip_space(&s);
	if (isneg)
		res = -res;
	if (*s != '\0' || int_overflows(res))
		return (FALSE);
	if (n)
		*n = (int)res;
	return (TRUE);
}
