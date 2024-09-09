/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:43:10 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 20:15:48 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_str	ft_strjoin(const t_str s1, const t_str s2)
{
	int		i;
	int		j;
	t_str	str;

	i = 0;
	j = 0;
	str = (t_str)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

t_str	ft_strjoin_free(const t_str s1, const t_str s2)
{
	t_str	s;

	s = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (s);
}
