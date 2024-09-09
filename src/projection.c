/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 00:01:40 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 22:11:24 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_bool	rotate_x(t_vec3d *p, double angle)
{
	t_int	y;

	if (!p)
		return (FALSE);
	y = p->y;
	p->y = y * cos(angle) + p->z * sin(angle);
	p->z = y * -sin(angle) + p->z * cos(angle);
	return (TRUE);
}

t_bool	rotate_y(t_vec3d *p, double angle)
{
	t_int	x;

	if (!p)
		return (FALSE);
	x = p->x;
	p->x = x * cos(angle) + p->z * sin(angle);
	p->z = x * -sin(angle) + p->z * cos(angle);
	return (TRUE);
}

t_bool	rotate_z(t_vec3d *p, double angle)
{
	t_intpair	xy;

	if (!p)
		return (FALSE);
	xy.x = p->x;
	xy.y = p->y;
	p->x = xy.x * cos(angle) - xy.y * sin(angle);
	p->y = xy.x * sin(angle) + xy.y * cos(angle);
	return (TRUE);
}

t_vec2d	project_point(t_env_fdf *env, t_int x, t_int y)
{
	t_vec2d	p;
	t_vec3d	p3d;
	t_int	z;

	if (x < 0 || y < 0 || x >= env->map->size.x || y >= env->map->size.y)
		exit(33);
	z = matrix_get(env->map->mat, x, y);
	p3d.x = x * env->camera->zoom;
	p3d.y = y * env->camera->zoom;
	p3d.z = z;
	p3d.z *= env->camera->zoom / env->camera->z_height;
	p3d.x -= (env->map->size.x * env->camera->zoom) / 2;
	p3d.y -= (env->map->size.y * env->camera->zoom) / 2;
	rotate_x(&p3d, env->camera->angle.x);
	rotate_y(&p3d, env->camera->angle.y);
	rotate_z(&p3d, env->camera->angle.z);
	p3d.x += SCREEN_WIDTH / 2 + env->camera->offset.x;
	p3d.y += SCREEN_HEIGHT / 2 + env->camera->offset.y;
	p.reverse = FALSE;
	p.x = p3d.x;
	p.y = p3d.y;
	p.color = matrix_get(env->map->colors, x, y);
	if (p.color < 0)
		p.color = point_color(env, z);
	return (p);
}
