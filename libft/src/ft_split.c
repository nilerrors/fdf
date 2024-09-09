/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:59:11 by senayat           #+#    #+#             */
/*   Updated: 2024/07/17 00:34:16 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_str	*ft_malloc_error(t_str *tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_split_len(const t_str s, char c)
{
	size_t	i;
	size_t	l;

	if (!s || !s[0])
		return (0);
	i = 0;
	l = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			l++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		l++;
	return (l);
}

static t_str	ft_nth_split_begin(const t_str s, char c, size_t n)
{
	size_t	i;
	size_t	current;

	i = 0;
	current = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (current == n)
			break ;
		if (s[i] == c)
		{
			current++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i] == 0)
		return (NULL);
	return ((t_str)(s + i));
}

static t_str	ft_nth_split(const t_str s, char c, int n)
{
	size_t	i;
	t_str	temp;
	t_str	str;
	size_t	size;

	temp = ft_nth_split_begin(s, c, n);
	if (!temp)
		return (NULL);
	i = 0;
	size = 0;
	while (temp[i] && temp[i] != c)
	{
		i++;
		size++;
	}
	i = 0;
	str = (t_str)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_str	*ft_split(const t_str s, char c)
{
	size_t	i;
	size_t	len;
	t_str	*tab;
	t_str	str;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_split_len(s, c);
	tab = (t_str *)malloc(sizeof(t_str) * (len + 1));
	if (!tab)
		return (NULL);
	while (i < len)
	{
		str = ft_nth_split(s, c, i);
		if (!str)
			return (ft_malloc_error(tab));
		tab[i] = str;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
