/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:39:12 by senayat           #+#    #+#             */
/*   Updated: 2024/09/10 09:12:01 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static t_uint	count_width(t_str s)
{
	t_uint	i;
	t_uint	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

t_intpair	size_map(t_str filepath)
{
	t_fd		fd;
	t_intpair	size;
	t_str		line;
	t_uint		cwidth;

	size.x = -1;
	size.y = -1;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (size);
	size.x = 0;
	size.y = 0;
	line = get_next_line(fd);
	while (line)
	{
		size.y++;
		cwidth = count_width(line);
		if (size.x == 0)
			size.x = cwidth;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}

static t_bool	find_min_max_map(t_env_fdf *env)
{
	t_intpair	p;

	if (!env || !env->map || env->map->size.x <= 0 || env->map->size.y <= 0)
		return (FALSE);
	p.y = 0;
	env->map->min = matrix_get(env->map->mat, 0, 0);
	env->map->max = matrix_get(env->map->mat, 0, 0);
	while (p.y < env->map->size.y)
	{
		p.x = 0;
		while (p.x < env->map->size.x - 1)
		{
			if (matrix_get(env->map->mat, p.x, p.y) < env->map->min)
				env->map->min = matrix_get(env->map->mat, p.x, p.y);
			if (matrix_get(env->map->mat, p.x, p.y) > env->map->max)
				env->map->max = matrix_get(env->map->mat, p.x, p.y);
			p.x++;
		}
		p.y++;
	}
	return (TRUE);
}

t_bool	readin_map(t_fd fd, t_env_fdf *env)
{
	t_str		line;
	t_intpair	cpos;
	t_str		*tab;

	ft_memset(env->map->colors->vec, -1, env->map->colors->vec->size);
	cpos.y = 0;
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		free(line);
		if (!tab)
			return (FALSE);
		cpos.x = -1;
		while (tab[++cpos.x])
		{
			set_xy_color(env, cpos, tab[cpos.x]);
			matrix_set(env->map->mat, cpos.x, cpos.y, ft_atoi(tab[cpos.x]));
		}
		ft_free_tab((void **)tab);
		cpos.y++;
		line = get_next_line(fd);
	}
	find_min_max_map(env);
	return (TRUE);
}

t_bool	read_parse_map(t_str path, t_env_fdf *env)
{
	t_fd		fd;
	t_intpair	size;

	if (!path)
		return (FALSE);
	if (!ft_strendswith(path, ".fdf"))
		return (ft_retf("FdF: Wrong file format, expected '*.fdf'\n"));
	size = size_map(path);
	if (size.x == -1 && size.y == -1)
		return (ft_retf("FdF: File not found\n"));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_retf("FdF: error when opening file\n"));
	env->map = ft_calloc(1, sizeof(t_map));
	if (!env->map)
		return (ft_retf("FdF: Memory allocation error\n"));
	env->map->size = size;
	env->map->mat = matrix_create(env->map->size.x, env->map->size.y);
	if (!env->map->mat)
		return (ft_retf("FdF: Memory allocation error\n"));
	env->map->colors = matrix_create(env->map->size.x, env->map->size.y);
	if (!env->map->mat)
		return (ft_retf("FdF: Memory allocation error\n"));
	readin_map(fd, env);
	return (TRUE);
}
