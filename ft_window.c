/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:14:37 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/19 13:14:39 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/***
 * between_limits:
 * This function takes in a t_inf struct and a t_point struct as input.
 * It then checks if the point is within the current window dimensions.
 * If it is, the function returns 1, otherwise it returns 0.
 * 
*/
int	between_limits(t_inf *info, t_point p)
{
	if (1 == 2)
		info->x = 0;
	if (p.x > 0 && p.x < 1920 && p.y > 0 && p.y < 1080)
		return (1);
	else
		return (0);
}

/***
 * isometric:
 * his function takes in a t_inf struct and a t_point struct as input.
 * It then applies an isometric transformation to the point and 
 * 	 returns the transformed point.
 * The angle of the transformation is hard-coded as 30 degrees.
 * It also uses the formula of the isometric projection which
 *	 is a combination of rotation and translation.
 * 
*/
t_point	isometric(t_inf *info, t_point p_ori)
{
	int		previous_x;
	int		previous_y;
	t_point	p;

	previous_x = p_ori.x - (info->x / 2);
	previous_y = p_ori.y - (info->y / 2);
	previous_x *= info->multiplier;
	previous_y *= info->multiplier;
	p.x = (previous_x - previous_y) * cos(info->persp);
	p.y = (previous_x + previous_y) * sin(info->persp)
		- (p_ori.value * info->multiplier);
	p.value = p_ori.value * info->multiplier;
	p.x += (1920 / 2) + info->slide_x;
	p.y += (1080 / 2) + info->slide_y;
	p.color = p_ori.color;
	return (p);
}

/****
 * draw_fdf:
 * This function takes in a t_inf struct as input.
 * It then iterates through all the points in the 'map' 2D array within 
 *  the t_inf struct and for each point, it checks if it is not on the 
 *  first row or first column, then calls the draw_between_coords function
 *  to draw a line between the current point and the point above it or to 
 *  the left of it respectively.
 * 
*/
int	iterate_map(t_inf *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= info->y)
	{
		j = -1;
		while (++j < info->x)
		{
			if (i != 0)
				perspective(info, info->map[i][j], info->map[i - 1][j]);
			if (j != 0)
				perspective(info, info->map[i][j], info->map[i][j - 1]);
		}
	}
	return (0);
}

/**
 * create_window:
 * This function set up the window and draw the figure in loop.
 * 
 */
int	create_window(t_inf *info)
{
	mlx_clear_window(info->mlx, info->window);
	clear_window(info);
	iterate_map(info);
	mlx_put_image_to_window(info->mlx, info->window, info->img.img, 0, 0);
	mlx_loop(info->mlx);
	return (0);
}

/****
 * set_up_mlx:
 * This function takes in a t_inf struct as input.
 * It initializes the mlx library, creates a new window, creates a new image
 *  and gets the data address of the image using mlx functions.
 * Then it calls the put_window function to draw the map on the window and 
 *  enters the mlx loop to handle window events.
 * 
 * Returns 0 on success.
 * 
 * Returns -1 on failure.
 * 
 */
int	set_up_mlx(t_inf *info)
{
	info->mlx = mlx_init();
	if (info->mlx != NULL)
	{
		info->window = mlx_new_window(info->mlx, 1920, 1080, "FdF");
		if (info->window != NULL)
		{
			info->img.img = mlx_new_image(info->mlx, 1920, 1080);
			if (info->img.img != NULL)
			{
				info->img.addr = mlx_get_data_addr(info->img.img,
						&info->img.bits_per_pixel,
						&info->img.line_length, &info->img.endian);
				set_hook(info);
				create_window(info);
				return (0);
			}
		}
	}
	return (free_paint(info, "Something went wrong"));
}
