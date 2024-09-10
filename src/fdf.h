/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:20:26 by senayat           #+#    #+#             */
/*   Updated: 2024/09/10 09:36:06 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define SCREEN_WIDTH  1920
# define SCREEN_HEIGHT 1080

# define DEG_15_RAD 0.261799388
# define DEG_30_RAD 0.523598776
# define DEG_35_RAD 0.610865238
# define DEG_45_RAD 0.785398163

# define EVENT_CLOSE_WIN 17
# define EVENT_KEY_ESC 65307
# define EVENT_KEY_SPACE 32
# define EVENT_KEY_MINUS 45
# define EVENT_KEY_PLUS 61
# define EVENT_KEY_UP 65362
# define EVENT_KEY_DOWN 65364
# define EVENT_KEY_LEFT 65361
# define EVENT_KEY_RIGHT 65363
# define EVENT_KEY_A 97
# define EVENT_KEY_S 115
# define EVENT_KEY_D 100
# define EVENT_KEY_F 102
# define EVENT_KEY_H 104
# define EVENT_KEY_J 106
# define EVENT_KEY_K 107
# define EVENT_KEY_L 108

typedef struct s_intpair
{
	t_int	x;
	t_int	y;
}	t_intpair;

typedef struct s_vec2d
{
	t_int	x;
	t_int	y;
	t_int	color;
	t_bool	reverse;
}	t_vec2d;

typedef struct s_dvec2d
{
	double	x;
	double	y;
}	t_dvec2d;

typedef struct s_vec3d
{
	t_int	x;
	t_int	y;
	t_int	z;
}	t_vec3d;

typedef struct s_dvec3d
{
	double	x;
	double	y;
	double	z;
}	t_dvec3d;

typedef struct s_line2d
{
	t_vec2d		a;
	t_vec2d		b;
	t_bool		steep;
}	t_line2d;

typedef struct t_map
{
	t_intpair	size;
	t_int		min;
	t_int		max;
	t_matrix	*mat;
	t_matrix	*colors;
}	t_map;

typedef enum e_cam_view
{
	ISOMETRIC,
	PARALLEL,
	TOPDOWN,
	SIDE
}	t_cam_view;

typedef struct s_camera
{
	t_dvec3d	angle;
	float		z_height;
	t_vec2d		offset;
	t_int		zoom;
	t_int		zoom_init;
	t_cam_view	view;
}	t_camera;

typedef struct s_env_fdf
{
	t_ptr		mlx;
	t_ptr		win;
	t_data		img;
	t_bool		rerender;
	t_str		addr;
	t_int		bits_per_pixel;
	t_int		size_line;
	t_int		endian;
	t_map		*map;
	t_camera	*camera;
}	t_env_fdf;

t_bool		init_env_win(t_env_fdf *env);
t_int		close_env_win(t_env_fdf *env);
t_bool		add_env_win_controls(t_env_fdf *env);
t_int		render_next_frame(t_env_fdf *env);
t_bool		read_parse_map(t_str path, t_env_fdf *env);
t_bool		init_env_fdf(t_env_fdf *env);
t_bool		clean_env_fdf(t_env_fdf *env);

t_vec2d		project_point(t_env_fdf *env, t_int x, t_int y);
t_bool		draw_line2d(t_env_fdf *env, t_line2d *line);
t_bool		project_and_draw_line(
				t_env_fdf *env, t_intpair from, t_int to_x, t_int to_y);
t_int		pixel_color(t_line2d *l, t_int x, float factor);
t_int		point_color(t_env_fdf *env, t_int z);
t_bool		set_xy_color(t_env_fdf *env, t_intpair p, t_str s);

t_camera	*camera_init(t_env_fdf *env);
t_bool		change_perspective(t_camera *camera);

t_bool		pixel_put(t_env_fdf *env, int x, int y, int color);
t_int		color_from_rgb(t_uint r, t_uint g, t_uint b);
t_bool		swap_ints(t_int *a, t_int *b);
t_bool		swap_4_ints(t_int *a, t_int *b, t_int *c, t_int *d);
t_int		min(t_int a, t_int b);
t_int		max(t_int a, t_int b);

#endif // FDF_H
