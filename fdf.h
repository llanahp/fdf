/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:14:26 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/14 17:18:37 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include <math.h>
# include <mlx.h>

# ifndef PI
#  define PI 3.14159265358979323846
# endif

# ifndef MLX_KEY_PRESS
#  define MLX_KEY_PRESS 2
# endif

# ifndef MLX_KEY_PRESS_MASK
#  define MLX_KEY_PRESS_MASK 1
# endif

# ifndef DESTROYNOTIFY
#  define DESTROYNOTIFY 17
# endif

# ifndef WHITE
#  define WHITE 0xFFFFFF
# endif

# ifndef BLACK
#  define BLACK 0x000000
# endif

# ifndef ESC
#  define ESC 53
# endif

# ifndef A
#  define A 2
# endif

# ifndef S
#  define S 13
# endif

# ifndef D
#  define D 0
# endif

# ifndef W
#  define W 1
# endif

# ifndef P
#  define P 35
# endif

# ifndef MINUS
#  define MINUS 78
# endif

# ifndef PLUS
#  define PLUS 69
# endif

# ifndef ESC_LINUX
#  define ESC_LINUX 65307
# endif

# ifndef RAD_30
#  define RAD_30 0.523599
# endif

# ifndef RAD_10
#  define RAD_10 0.174533
# endif

typedef struct s_point
{
	int				x;
	int				y;
	int				value;
	unsigned int	color;
}				t_point;

typedef struct s_size
{
	int	width;
	int	height;
}				t_size;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_inf
{
	char	**argv;
	int		argc;
	int		in_file;
	int		x;
	int		y;
	t_point	**map;
	void	*mlx;
	void	*window;
	t_data	img;
	int		dx;
	int		dy;
	int		err;
	int		e2;
	int		sx;
	int		sy;
	int		multiplier;
	int		slide_x;
	int		slide_y;
	double	persp;
}	t_inf;

void			open_input(t_inf *info);
int				store_line(char **line, t_inf *info);
double			percent(int start, int end, int current);
unsigned int	get_color(t_point p_start, t_point p_end, double module);
unsigned int	set_color(char *string);
int				hex_to_int(char *hex);
int				correct_extension(char *string, char *extension);
void			free_split(char **content);
void			free_map(t_inf *info);
int				free_paint(t_inf *info, char *msg_error);
void			msg_error(char *msg);
char			*validate_position(char	*line);
int				check_line(char *line, t_inf *info);
void			validate_input(t_inf *info);
int				set_up_mlx(t_inf *info);
int				between_limits(t_inf *info, t_point p);
int				get_red(char *string);
int				get_green(char *string);
int				get_blue(char *string);
void			set_hook(t_inf *info);
int				key_press(int key, t_inf *info);
int				close_fdf(t_inf *info);
int				iterate_map(t_inf *info);
int				create_window(t_inf *info);
void			put_pixel(t_data *info, int x, int y, unsigned int color);
void			draw_line(t_inf *info, t_point *p_start, t_point *p_end);
double			get_percentage(t_inf *info, t_point start,
					t_point end, t_point actual);
void			perspective(t_inf *info, t_point start, t_point end);
t_point			isometric(t_inf *info, t_point p_ori);
void			get_pixel(t_inf *info, t_point start,
					t_point current, t_point end);
void			draw_line(t_inf *info, t_point *current, t_point *end);
void			clear_window(t_inf *info);
void			adjust_multiplier(t_inf *info);
#endif