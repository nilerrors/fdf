/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:30:32 by senayat           #+#    #+#             */
/*   Updated: 2024/09/08 22:30:21 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	ft_ipart(float n)
{
	return ((int)n);
}

float	ft_fpart(float n)
{
	if (n > 0.f)
		return (n - ft_ipart(n));
	return (n - (ft_ipart(n) + 1.f));
}

float	ft_rfpart(float n)
{
	return (1.f - ft_fpart(n));
}

t_bool	draw_line_loop(t_env_fdf *env, t_line2d *l, float gradient)
{
	float	inter_y;
	int		x;

	if (!env || !l)
		return (FALSE);
	inter_y = (float)l->a.y;
	x = l->a.x;
	while (x <= l->b.x)
	{
		if (env->steep)
		{
			pixel_put(env, (int)inter_y, x,
				pixel_color(l, x, ft_rfpart(inter_y)));
			pixel_put(env, (int)inter_y + 1, x,
				pixel_color(l, x, ft_fpart(inter_y)));
		}
		else
		{
			pixel_put(env, x, (int)inter_y,
				pixel_color(l, x, ft_rfpart(inter_y)));
			pixel_put(env, x, (int)inter_y + 1,
				pixel_color(l, x, ft_fpart(inter_y)));
		}
		inter_y += gradient;
		x++;
	}
	return (TRUE);
}

t_bool	draw_line2d(t_env_fdf *env, t_line2d *l)
{
	float	dy;
	float	dx;
	float	gradient;

	if (!env || !l)
		return (FALSE);
	env->steep = abs(l->b.y - l->a.y) > abs(l->b.x - l->a.x);
	if (env->steep)
		swap_4_ints(&l->a.x, &l->a.y, &l->b.x, &l->b.y);
	if (l->a.x > l->b.x)
		swap_4_ints(&l->a.x, &l->b.x, &l->a.y, &l->b.y);
	dx = (float)(l->b.x - l->a.x);
	dy = (float)(l->b.y - l->a.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	draw_line_loop(env, l, gradient);
	return (TRUE);
}

t_bool	project_and_draw_line(t_env_fdf *env, t_intpair from, t_int to_x, t_int to_y)
{
	t_line2d	l;

	if (!env)
		return (FALSE);
	l.a = project_point(env, from.x, from.y);
	l.b = project_point(env, to_x, to_y);
	draw_line2d(env, &l);
	return (TRUE);
}
