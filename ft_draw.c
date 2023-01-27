/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:14:37 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/19 13:14:39 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/***
 * put_pixel:
 * This function takes in a t_data struct, an x coordinate, a y coordinate, 
 * and a color as input. 
 * It then sets the pixel at the specified (x,y) coordinate 
 *	to the specified color.
 * 
*/
void	put_pixel(t_data *info, int x, int y, unsigned int color)
{
	char	*dst;

	dst = info->addr + (y * info->line_length + x * (info->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
 * get_pixel:
 * This function gets the color of one pixel and if it is between the limits,
 * 	draws it.
 * 
 */
void	get_pixel(t_inf *info, t_point start, t_point current, t_point p_end)
{
	double			percentage;
	unsigned int	color;

	percentage = get_percentage(info, start, p_end, current);
	if (between_limits(info, current) == 1)
	{
		if (current.color == p_end.color)
			put_pixel(&info->img, current.x, current.y, current.color);
		else
		{
			color = get_color(current, p_end, percentage);
			put_pixel(&info->img, current.x, current.y, color);
		}
	}
}

/****
 * draw_between_coords:
 * This function takes the starting and ending points, applies an isometric 
 *  transformation, checks if the points are within the window, and if so,
 *  draws a line between the transformed points. 
*/
void	perspective(t_inf *info, t_point start, t_point end)
{
	t_point	p_start;
	t_point	p_end;

	p_start = isometric(info, start);
	p_end = isometric(info, end);
	draw_line(info, &p_start, &p_end);
}

/**
 * clear_window:
 * This function sets al the window to dark.
 * 
 */
void	clear_window(t_inf *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 1920)
	{
		j = -1;
		while (++j < 1080)
		{
			put_pixel(&info->img, i, j, BLACK);
		}
	}
}
