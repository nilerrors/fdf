/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:07:03 by senayat           #+#    #+#             */
/*   Updated: 2024/09/09 13:07:32 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_int	handle_key_input(int key, t_env_fdf *env)
{
	if (!env)
		return (0);
	ft_printf("Key pressed: %d\n", key);
	if (key == EVENT_KEY_ESC)
		close_env_win(env);
	if (key == EVENT_KEY_SPACE)
		change_perspective(env->camera);
	env->rerender = TRUE;
	return (0);
}

t_bool	add_env_win_controls(t_env_fdf *env)
{
	mlx_hook(env->win, EVENT_CLOSE_WIN, 0, close_env_win, env);
	mlx_key_hook(env->win, handle_key_input, env);
	return (TRUE);
}
