/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_getset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:14:24 by senayat           #+#    #+#             */
/*   Updated: 2024/07/06 20:55:56 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	vector_set(t_vector *list, size_t index, int new_item)
{
	if (!list || index >= list->size)
		return (FALSE);
	list->items[index] = new_item;
	return (TRUE);
}

t_bool	vector_get(t_vector *list, size_t index, int *item)
{
	if (!list || index >= list->size)
		return (FALSE);
	*item = list->items[index];
	return (TRUE);
}

t_bool	vector_find(t_vector *list, int item, size_t *index)
{
	size_t	i;
	int		n;

	if (!list)
		return (FALSE);
	i = 0;
	while (i < list->size)
	{
		if (!vector_get(list, i, &n))
			break ;
		if (item == n)
		{
			if (index)
				*index = i;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
