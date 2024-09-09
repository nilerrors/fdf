/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 00:45:15 by senayat           #+#    #+#             */
/*   Updated: 2024/09/07 13:20:13 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	main(int argc, char **argv)
{
	t_env_fdf	env;
	t_bool		should_clean;

	if (argc != 2)
	{
		ft_printerr("FdF: wrong input, expected: %s [*.fdf]\n", argv[0]);
		return (1);
	}
	init_env_fdf(&env);
	should_clean = !read_parse_map(argv[1], &env)
		|| !init_env_win(&env)
		|| !add_env_win_controls(&env);
	if (should_clean)
		return (clean_env_fdf(&env) || 1);
	mlx_loop_hook(env.mlx, render_next_frame, &env);
	mlx_loop(env.mlx);
	return (0);
}
