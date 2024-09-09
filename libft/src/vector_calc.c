/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:34:34 by senayat           #+#    #+#             */
/*   Updated: 2024/07/06 20:55:31 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	vector_mean(t_vector *list, long *mean)
{
	size_t	i;
	int		n;
	long	sum;

	if (!list || !list->size)
		return (FALSE);
	i = 0;
	sum = 0;
	while (i < list->size)
	{
		vector_get(list, i, &n);
		sum += n;
		i++;
	}
	*mean = sum / (long)list->size;
	return (TRUE);
}

t_bool	vector_find_smallest(t_vector *list, size_t *index)
{
	size_t	i;
	int		n;
	int		cur;

	if (!list || !list->size)
		return (FALSE);
	i = 1;
	vector_get(list, 0, &n);
	while (i < list->size)
	{
		vector_get(list, i, &cur);
		if (cur < n)
			n = cur;
		i++;
	}
	vector_find(list, n, index);
	return (TRUE);
}

int	vector_cost_move_to_top(size_t size, size_t index)
{
	if (index <= size / 2)
		return (index);
	else if (index > size / 2)
		return (size - index);
	return (0);
}
