/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_close_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:03:59 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 23:29:33 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_bool	init_env_fdf(t_env_fdf *env)
{
	if (!env)
		return (FALSE);
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->map = NULL;
	env->camera = NULL;
	env->rerender = TRUE;
	env->addr = NULL;
	env->bits_per_pixel = 0;
	env->size_line = 0;
	env->endian = 0;
	return (TRUE);
}

t_bool	clean_env_fdf(t_env_fdf *env)
{
	if (!env || !env->mlx)
		return (FALSE);
	if (env->map)
		(void)(matrix_destroy(env->map->mat)
				&& matrix_destroy(env->map->colors));
	free(env->map);
	free(env->camera);
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	env->img = NULL;
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	env->win = NULL;
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	env->mlx = NULL;
	return (TRUE);
}

t_bool	init_env_win(t_env_fdf *env)
{
	if (!env)
		return (FALSE);
	env->mlx = mlx_init();
	if (!env->mlx)
		return (FALSE);
	env->win = mlx_new_window(env->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FdF");
	if (!env->win)
		return (FALSE);
	env->img = mlx_new_image(env->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!env->img)
		return (FALSE);
	env->addr = mlx_get_data_addr(
			env->img, &env->bits_per_pixel, &env->size_line, &env->endian);
	if (!env->addr)
		return (FALSE);
	env->camera = camera_init(env);
	if (!env->camera)
		return (FALSE);
	return (TRUE);
}

int	close_env_win(t_env_fdf *env)
{
	if (!env)
		return (FALSE);
	clean_env_fdf(env);
	exit(0);
	return (TRUE);
}
