/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:53:04 by senayat           #+#    #+#             */
/*   Updated: 2024/09/08 22:55:04 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_bool	swap_ints(t_int *a, t_int *b)
{
	t_int	t;

	if (!a || !b)
		return (FALSE);
	t = *a;
	*a = *b;
	*b = t;
	return (TRUE);
}

t_bool	swap_4_ints(t_int *a, t_int *b, t_int *c, t_int *d)
{
	return (swap_ints(a, b) && swap_ints(c, d));
}

t_int	min(t_int a, t_int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_int	max(t_int a, t_int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

t_int	pixel_color(t_line2d *l, t_int x, float factor)
{
	int		r;
	int		g;
	int		b;
	double	percent;

	if (!l)
		return (0);
	percent = (double)abs(x - l->a.x) / (double)abs(l->b.x - l->a.x);
	r = lerp((l->a.color >> 16) & 0xFF, (l->b.color >> 16) & 0xFF, percent);
	g = lerp((l->a.color >> 8) & 0xFF, (l->b.color >> 8) & 0xFF, percent);
	b = lerp(l->a.color & 0xFF, l->b.color & 0xFF, percent);
	//
	// if (s.reverse)
	// {
	// 	r = ft_lerp((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
	// 	g = ft_lerp((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
	// 	b = ft_lerp(e.color & 0xFF, s.color & 0xFF, percent);
	// }
	// else
	// {
	// 	r = ft_lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
	// 	g = ft_lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
	// 	b = ft_lerp(s.color & 0xFF, e.color & 0xFF, percent);
	// }
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b);
}

t_int	point_color(t_env_fdf *env, t_int z)
{

	double			percent;
	unsigned int	max;

	max = env->map->max - env->map->min;
	if (max == 0)
		return (color_from_rgb(0, 100, 255));
	percent = ((double)(z - env->map->min) / max);
	if (percent < 0.2)
		return (color_from_rgb(0, 145, 255));
	else if (percent < 0.4)
		return (color_from_rgb(224, 247, 255));
	else if (percent < 0.6)
		return (color_from_rgb(209, 255, 217));
	else if (percent < 0.8)
		return (color_from_rgb(129, 77, 25));
	else
		return (color_from_rgb(255, 0, 89));
}
