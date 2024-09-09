/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:41:56 by senayat           #+#    #+#             */
/*   Updated: 2024/07/20 00:45:45 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_str	ft_strtrim(const t_str s1, const t_str set)
{
	size_t	i;
	size_t	j;
	t_str	str;

	if (!s1 || !set)
		return (NULL);
	str = NULL;
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
		j--;
	str = (t_str)malloc(sizeof(char) * (j - i + 1));
	if (str)
		ft_strlcpy(str, &s1[i], j - i + 1);
	return (str);
}
