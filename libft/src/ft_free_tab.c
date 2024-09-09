/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:43:33 by senayat           #+#    #+#             */
/*   Updated: 2024/07/17 00:26:02 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	ft_set_free(t_data *ptr)
{
	if (!ptr || !*ptr)
		return (FALSE);
	free(*ptr);
	*ptr = NULL;
	return (TRUE);
}

t_bool	ft_free_tab(t_data *tab)
{
	size_t	i;

	if (!tab)
		return (FALSE);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (TRUE);
}
