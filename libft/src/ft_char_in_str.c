/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_in_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:42:39 by senayat           #+#    #+#             */
/*   Updated: 2024/07/17 00:15:47 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	ft_char_in_str(char c, const t_str str)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (TRUE);
	return (FALSE);
}
