/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:49:09 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 16:21:23 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"


t_camera	*camera_init(t_env_fdf *env)
{
	t_camera	*camera;

	camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->view = ISOMETRIC;
	camera->angle.x = -DEG_35_RAD;
	camera->angle.y = -DEG_35_RAD;
	camera->angle.z = DEG_35_RAD;
	camera->z_height = 1.0;
	camera->zoom = min(SCREEN_WIDTH / env->map->size.x / 2,
			SCREEN_HEIGHT / env->map->size.y / 2);
	return (camera);
}

t_bool	change_angles(t_camera *camera, double x, double y, double z)
{
	if (!camera)
		return (FALSE);
	camera->angle.x = x;
	camera->angle.y = y;
	camera->angle.z = z;
	return (TRUE);
}

t_bool	change_perspective(t_camera *camera)
{
	if (!camera)
		return (FALSE);
	if (camera->view == ISOMETRIC)
	{
		camera->view = PARALLEL;
		change_angles(camera, -DEG_30_RAD, -DEG_15_RAD, 0.0);
	}
	else if (camera->view == PARALLEL)
	{
		camera->view = BIRDSEYE;
		change_angles(camera, DEG_45_RAD, DEG_30_RAD, -DEG_45_RAD);
		camera->z_height = 1.2;
	}
	else if (camera->view == BIRDSEYE)
	{
		camera->view = TOPDOWN;
		change_angles(camera, 0.0, 0.0, 0.0);
		camera->z_height = 1.0;
	}
	else
	{
		camera->view = ISOMETRIC;
		change_angles(camera, -DEG_35_RAD, -DEG_35_RAD, DEG_35_RAD);
	}
	return (TRUE);
}
