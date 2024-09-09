/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:05:35 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 16:20:40 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#include <stdio.h>

t_bool	pixel_put(t_env_fdf *env, int x, int y, int color)
{
	t_str	dst;

	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return (FALSE);
	dst = env->addr + (y * env->size_line + x * (env->bits_per_pixel / 8));
	*(t_uint *)dst = color;
	return (TRUE);
}

int	color_from_rgb(t_uint r, t_uint g, t_uint b)
{
	r %= 256;
	g %= 256;
	b %= 256;
	return ((r << 16) | (g << 8) | b);
}

t_bool	set_xy_color(t_env_fdf *env, t_intpair p, t_str s)
{
	if (!env || !s || !env->map || !env->map->colors)
		return (FALSE);
	if (!ft_char_in_str(',', s))
		return (matrix_set(env->map->colors, p.x, p.y, -1));
	s = ft_strchr(s, ',') + sizeof(char);
	if (ft_strlen(s) <= 2 || (s[0] != '0' && s[1] != 'x'))
		return (matrix_set(env->map->colors, p.x, p.y, -1) && FALSE);
	s += 2 * sizeof(char);
	matrix_set(env->map->colors, p.x, p.y, ft_htoi(s));
	return (TRUE);
}

t_bool	render_stats(t_env_fdf *env)
{
	t_str	s;
	t_str	fs;

	if (!env)
		return (FALSE);
	s = ft_ftoa(env->camera->angle.x);
	if (!s)
		return (FALSE);
	fs = ft_strjoin("Camera angle x:  ", s);
	free(s);
	if (!fs)
		return (FALSE);
	mlx_string_put(env->mlx, env->win, 5, 10, 0xFFFFFF, fs);
	free(fs);
	s = ft_ftoa(env->camera->angle.y);
	if (!s)
		return (FALSE);
	fs = ft_strjoin("Camera angle y:  ", s);
	free(s);
	if (!fs)
		return (FALSE);
	mlx_string_put(env->mlx, env->win, 5, 30, 0xFFFFFF, fs);
	free(fs);
	s = ft_ftoa(env->camera->angle.z);
	if (!s)
		return (FALSE);
	fs = ft_strjoin("Camera angle z:  ", s);
	free(s);
	if (!fs)
		return (FALSE);
	mlx_string_put(env->mlx, env->win, 5, 50, 0xFFFFFF, fs);
	free(fs);
	s = ft_ftoa(env->camera->z_height);
	if (!s)
		return (FALSE);
	fs = ft_strjoin("Camera z height: ", s);
	free(s);
	if (!fs)
		return (FALSE);
	mlx_string_put(env->mlx, env->win, 5, 70, 0xFFFFFF, fs);
	free(fs);
	s = ft_itoa(env->camera->zoom);
	if (!s)
		return (FALSE);
	fs = ft_strjoin("Camera zoom:     ", s);
	free(s);
	if (!fs)
		return (FALSE);
	mlx_string_put(env->mlx, env->win, 5, 90, 0xFFFFFF, fs);
	free(fs);
	s = ft_itoa(env->map->min);
	if (!s)
		return (FALSE);
	fs = ft_strjoin("Map min:         ", s);
	free(s);
	if (!fs)
		return (FALSE);
	mlx_string_put(env->mlx, env->win, 5, 110, 0xFFFFFF, fs);
	free(fs);
	s = ft_itoa(env->map->max);
	if (!s)
		return (FALSE);
	fs = ft_strjoin("Map max:         ", s);
	free(s);
	if (!fs)
		return (FALSE);
	mlx_string_put(env->mlx, env->win, 5, 130, 0xFFFFFF, fs);
	free(fs);
	return (TRUE);
}

int	render_next_frame(t_env_fdf *env)
{
	t_intpair	p;

	if (!env || !env->rerender)
		return (0);
	ft_bzero(env->addr, SCREEN_WIDTH * SCREEN_HEIGHT * (env->bits_per_pixel / 8));
	p.y = 0;
	if (env->camera->angle.x > 0)
		p.y = env->map->size.y - 1;
	while (p.y >= 0 && p.y < env->map->size.y)
	{
		p.x = 0;
		if (env->camera->angle.y > 0)
			p.x = env->map->size.x - 1;
		while (p.x >= 0 && p.x < env->map->size.x)
		{
			if (p.x != env->map->size.x - 1)
				project_and_draw_line(env, p, p.x + 1, p.y);
			if (p.y != env->map->size.y - 1)
				project_and_draw_line(env, p, p.x, p.y + 1);
			p.x += 1 - 2 * (env->camera->angle.y > 0);
		}
		p.y += 1 - 2 * (env->camera->angle.x > 0);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	render_stats(env);
	env->rerender = FALSE;
	return (0);
}
