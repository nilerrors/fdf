/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:07:03 by senayat           #+#    #+#             */
/*   Updated: 2024/09/10 09:42:55 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static t_bool	handle_rotation_keys(int key, t_env_fdf *env)
{
	if (!env)
		return (FALSE);
	if (key == EVENT_KEY_H)
		env->camera->angle.x += 0.1;
	if (key == EVENT_KEY_J)
		env->camera->angle.y += 0.1;
	if (key == EVENT_KEY_K)
		env->camera->angle.z += 0.1;
	if (key == EVENT_KEY_L)
		env->camera->z_height += 0.1;
	if (key == EVENT_KEY_A)
		env->camera->angle.x -= 0.1;
	if (key == EVENT_KEY_S)
		env->camera->angle.y -= 0.1;
	if (key == EVENT_KEY_D)
		env->camera->angle.z -= 0.1;
	if (key == EVENT_KEY_F)
		env->camera->z_height = fmax(0.1, env->camera->z_height - 0.1);
	return (TRUE);
}

static t_int	handle_key_input(int key, t_env_fdf *env)
{
	if (!env)
		return (0);
	if (key == EVENT_KEY_ESC)
		close_env_win(env);
	if (key == EVENT_KEY_SPACE)
		change_perspective(env->camera);
	if (key == EVENT_KEY_MINUS)
		env->camera->zoom = fmax(1.0,
				env->camera->zoom - (float)env->camera->zoom_init / 2);
	if (key == EVENT_KEY_PLUS)
		env->camera->zoom += 1 + (float)env->camera->zoom_init / 2;
	if (key == EVENT_KEY_LEFT)
		env->camera->offset.x -= 10;
	if (key == EVENT_KEY_UP)
		env->camera->offset.y -= 10;
	if (key == EVENT_KEY_DOWN)
		env->camera->offset.y += 10;
	if (key == EVENT_KEY_RIGHT)
		env->camera->offset.x += 10;
	handle_rotation_keys(key, env);
	env->rerender = TRUE;
	return (0);
}

t_bool	add_env_win_controls(t_env_fdf *env)
{
	mlx_hook(env->win, EVENT_CLOSE_WIN, 0, close_env_win, env);
	mlx_key_hook(env->win, handle_key_input, env);
	return (TRUE);
}
