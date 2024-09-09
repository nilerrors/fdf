/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:45:56 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 19:59:33 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const t_str str)
{
	size_t	i;
	int		negative;
	int		result;

	i = 0;
	negative = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (negative)
		result = -result;
	return (result);
}

int	ft_htoi(const t_str str)
{
	size_t	i;
	int		negative;
	int		result;

	i = 0;
	negative = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	i += (str[i] == '+' || str[i] == '-');
	negative = str[i - 1] == '-';
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F')
		|| (str[i] >= 'a' && str[i] <= 'f'))
	{
		result *= 16;
		if ((str[i] >= '0' && str[i] <= '9'))
			result += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += str[i++] - 'a' + 10;
	}
	if (negative)
		result = -result;
	return (result);
}
