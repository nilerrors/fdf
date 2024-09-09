/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:30:34 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 22:10:38 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_matrix	*matrix_create(t_uint x, t_uint y)
{
	t_matrix	*mat;

	mat = (t_matrix *)ft_calloc(1, sizeof(t_matrix));
	if (!mat)
		return (NULL);
	mat->row = y;
	mat->col = x;
	mat->vec = vector_create(mat->row * mat->col);
	if (!mat->vec && ft_set_free((t_data)(&mat)))
		return (NULL);
	return (mat);
}

t_bool	matrix_destroy(t_matrix *mat)
{
	if (!mat)
		return (FALSE);
	vector_destroy(mat->vec);
	free(mat);
	return (TRUE);
}

t_int	matrix_get(t_matrix *m, t_uint x, t_uint y)
{
	if (x >= m->col || y >= m->row)
		exit(69);
	return (m->vec->items[m->col * y + x]);
}

t_bool	matrix_set(t_matrix *m, t_uint x, t_uint y, t_int val)
{
	if (x >= m->col || y >= m->row)
		return (FALSE);
	m->vec->items[m->col * y + x] = val;
	return (TRUE);
}
