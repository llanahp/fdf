/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:14:37 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/19 13:14:39 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * ajust_line:
 * This function adjusts the line based on the error value.
 * It updates the x and y coordinates of the line 
 * 	by adding the sign of x and y, respectively.
 * 
 */
void	ajust_line(t_inf *info, t_point *p_start)
{
	info->e2 = info->err;
	if (info->e2 > -info->dx)
	{
		info->err -= info->dy;
		p_start->x += info->sx;
	}
	if (info->e2 < info->dy)
	{
		info->err += info->dx;
		p_start->y += info->sy;
	}
}

/**
 * set_up_bresenham:
 * This function initializes the values for the Bresenham's algorithm such as 
 * the difference between x and y coordinates of the line, the sign 
 * 	of x and y, and the error value.
 * 
 */
void	set_up_bresenham(t_inf *info, t_point *current, t_point *end)
{
	info->dx = abs(end->x - current->x);
	if (current->x < end->x)
		info->sx = 1;
	else
		info->sx = -1;
	info->dy = abs(end->y - current->y);
	if (current->y < end->y)
		info->sy = 1;
	else
		info->sy = -1;
	if (info->dx > info->dy)
		info->err = info->dx / 2;
	else
		info->err = -info->dy / 2;
}

/***
 * draw_line:
 * This function uses the Bresenham's algorithm to draw 
 * 	the line between 2 points.
 * It calls the set_up_bresenham function to initialize the values, 
 * 	and then enters a loop until the current point reaches the end point.
 * 
 * In each iteration of the loop, it calls the ajust_line function 
 * 	and the get_pixel function.
 * The get_pixel function is not provided in this code snippet, 
 * 	so it is unclear what it does.
 * Once the loop exits, it makes one final call to the get_pixel function.
 * 
 * 
*/
void	draw_line(t_inf *info, t_point *current, t_point *end)
{
	t_point	start;

	set_up_bresenham(info, current, end);
	start.x = current->x;
	start.y = current->y;
	while (!(current->x == end->x && current->y == end->y))
	{
		get_pixel(info, start, *current, *end);
		ajust_line(info, current);
	}
	get_pixel(info, start, *current, *end);
}
