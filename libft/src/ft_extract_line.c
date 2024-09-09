/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:34:09 by senayat           #+#    #+#             */
/*   Updated: 2024/07/20 00:45:23 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_str	ft_extract_line(const t_str from)
{
	t_str	line;
	size_t	i;

	if (!from || !from[0])
		return (NULL);
	i = 0;
	while (from[i] && from[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	if (from[i] == '\n')
		line[i] = '\n';
	while (i > 0)
	{
		i--;
		line[i] = from[i];
	}
	return (line);
}

t_str	ft_extract_line_no_endl(const t_str from)
{
	t_str	line;
	size_t	i;

	if (!from || !from[0])
		return (NULL);
	i = 0;
	while (from[i] && from[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (i > 0)
	{
		i--;
		line[i] = from[i];
	}
	return (line);
}
