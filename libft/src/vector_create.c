/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:11:19 by senayat           #+#    #+#             */
/*   Updated: 2024/09/06 15:39:31 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector	*vector_create(size_t capacity)
{
	t_vector	*arr;
	int			*items;

	arr = (t_vector *)ft_calloc(1, sizeof(t_vector));
	if (!arr)
		return (NULL);
	arr->size = 0;
	arr->capacity = capacity;
	items = (int *)ft_calloc(arr->capacity, sizeof(int));
	if (!items)
	{
		free(arr);
		return (NULL);
	}
	arr->items = items;
	return (arr);
}
