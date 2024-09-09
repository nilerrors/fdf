/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:05:35 by senayat           #+#    #+#             */
/*   Updated: 2024/09/10 00:43:02 by senayat          ###   ########.fr       */
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

static t_bool	render_text(t_env_fdf *env, t_str str, float n, t_int y)
{
	t_str	s;
	t_str	fs;

	s = ft_ftoa(n);
	if (!s)
		return (FALSE);
	fs = ft_strjoin(str, s);
	free(s);
	if (!fs)
		return (FALSE);
	mlx_string_put(env->mlx, env->win, 10, y, 0xFFFFFF, fs);
	free(fs);
	return (TRUE);
}

static t_bool	render_stats(t_env_fdf *env)
{
	t_bool	not_ok;

	not_ok = FALSE;
	if (!env)
		return (FALSE);
	not_ok = !render_text(env, "Camera angle x:  ", env->camera->angle.x, 20)
		|| !render_text(env, "Camera angle y:  ", env->camera->angle.y, 40)
		|| !render_text(env, "Camera angle z:  ", env->camera->angle.z, 60)
		|| !render_text(env, "Camera z height: ", env->camera->z_height, 80)
		|| !render_text(env, "Camera zoom:     ", env->camera->zoom, 100)
		|| !render_text(env, "Map min:         ", env->map->min, 120)
		|| !render_text(env, "Map max:         ", env->map->max, 140);
	if (env->camera->view == ISOMETRIC)
		mlx_string_put(env->mlx, env->win, 10, 160,
			0xFFFFFF, "Perspective:     Isometric");
	if (env->camera->view == PARALLEL)
		mlx_string_put(env->mlx, env->win, 10, 160,
			0xFFFFFF, "Perspective:     Parallel");
	if (env->camera->view == TOPDOWN)
		mlx_string_put(env->mlx, env->win, 10, 160,
			0xFFFFFF, "Perspective:     Topdown");
	if (env->camera->view == SIDE)
		mlx_string_put(env->mlx, env->win, 10, 160,
			0xFFFFFF, "Perspective:     Side-view");
	return (!not_ok);
}

int	render_next_frame(t_env_fdf *env)
{
	t_intpair	p;

	if (!env || !env->rerender)
		return (0);
	ft_bzero(env->addr,
		SCREEN_WIDTH * SCREEN_HEIGHT * (env->bits_per_pixel / 8));
	p.y = 0 + (env->map->size.y - 1) * (env->camera->angle.x > 0);
	while (p.y >= 0 && p.y < env->map->size.y)
	{
		p.x = 0 + (env->map->size.x - 1) * (env->camera->angle.y > 0);
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
