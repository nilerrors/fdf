/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:58:36 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 20:16:19 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_nbrlen(long int nbr)
{
	size_t	len;

	len = (nbr <= 0);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static t_str	ft_itoa_neg2147483648(void)
{
	t_str	str;

	str = (t_str)malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

t_str	ft_itoa(int n)
{
	size_t	len;
	int		negative;
	t_str	str;

	if (n == -2147483648)
		return (ft_itoa_neg2147483648());
	negative = (n < 0);
	len = ft_nbrlen(n);
	if (n < 0)
		n = -n;
	if (n < 0)
		len++;
	str = (t_str)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

t_int	extract_decimal_part(float num)
{
	t_int	i;
	float	d;
	t_int	scale;

	if (num < 0)
		num = -num;
	i = (int)num;
	d = num - i;
	scale = 1;
	while ((d * scale) - (int)(d * scale) > 0.00001)
		scale *= 10;
	return ((int)(d * scale));
}

t_str	ft_ftoa(float n)
{
	t_str	s;
	t_str	si;
	t_str	sd;

	si = ft_itoa((int)n);
	if (!si)
		return (NULL);
	if (n < 0.0 && n > -1.0)
	{
		s = ft_strjoin("-", si);
		free(si);
		if (!s)
			return (NULL);
		si = s;
	}
	s = ft_strjoin(si, ".");
	free(si);
	if (!s)
		return (NULL);
	sd = ft_itoa(extract_decimal_part(n));
	if (!sd)
		return (ft_make_free((void **)&s));
	return (ft_strjoin_free(s, sd));
}
