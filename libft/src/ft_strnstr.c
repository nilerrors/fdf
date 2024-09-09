/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:06:16 by senayat           #+#    #+#             */
/*   Updated: 2024/07/20 00:35:14 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_str_startswith(const t_str s, const t_str w, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && w[i] && i < n)
	{
		if (s[i] != w[i])
			return (0);
		i++;
	}
	return (w[i] == '\0');
}

t_str	ft_strnstr(const t_str haystack, const t_str needle, size_t len)
{
	size_t	i;

	if (needle[0] == '\0')
		return ((t_str)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (ft_str_startswith(haystack + i, needle, len - i))
			return ((t_str)(haystack + i));
		i++;
	}
	return (NULL);
}
