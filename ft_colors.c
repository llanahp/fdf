/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:37:36 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/19 19:37:38 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/****
 * get_red:
 * This function get the red channel color and returns the color 
 * 
 * Returns between 0 - 255
 * 
*/
int	get_red(char *string)
{
	int		red;
	char	*color;

	color = ft_substr(string, 2, 2);
	red = hex_to_int(color);
	free(color);
	return (red);
}

/****
 * geget_greent_red:
 * This function get the green channel color and returns the color 
 * 
 * Returns between 0 - 255
 * 
*/
int	get_green(char *string)
{
	int		green;
	char	*color;

	color = ft_substr(string, 4, 2);
	green = hex_to_int(color);
	free(color);
	return (green);
}

/****
 * get_blue:
 * This function get the blue channel color and returns the color 
 * 
 * Returns between 0 - 255
 * 
*/
int	get_blue(char *string)
{
	int		blue;
	char	*color;

	color = ft_substr(string, 6, 2);
	blue = hex_to_int(color);
	free(color);
	return (blue);
}	

/***
 * get_color:
 * This function interpolates the color value of two t_point structs 
 *  (p_current and p_end) based on a percentage (porcentaje) and 
 *  returns the resulting color as an unsigned int.
 * 
 * It checks if the color of the two points are the same or if the x-coordinate
 *  of the current t_point is equal to the x-coordinate of the end point, 
 *  if true it returns the color of the end point.
 * 
*/
unsigned int	get_color(t_point p_current, t_point p_end, double porcentaje)
{
	t_point	r;
	t_point	g;
	t_point	b;

	if (p_current.color == p_end.color || p_current.x - p_end.x == 0)
		return (p_end.color);
	r.x = (p_current.color & 0xFF0000) >> 16;
	r.y = (p_end.color & 0xFF0000) >> 16;
	g.x = (p_current.color & 0x00FF00) >> 8;
	g.y = (p_end.color & 0x00FF00) >> 8;
	b.x = p_current.color & 0x0000FF;
	b.y = p_end.color & 0x0000FF;
	r.x = ((int)((1 - porcentaje) * r.x + porcentaje * r.y));
	g.x = ((int)((1 - porcentaje) * g.x + porcentaje * g.y));
	b.x = ((int)((1 - porcentaje) * b.x + porcentaje * b.y));
	return ((r.x << 16) | (g.x << 8) | b.x);
}

/***
 * set_color:
 * This function recives a string whith an hex color.
 * Split hex color to each channel and transform to integer
 * 
 * Returns int color code.
 * 
*/
unsigned int	set_color(char *string)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = get_red(string);
	g = get_green(string);
	b = get_blue(string);
	return (t << 24 | r << 16 | g << 8 | b);
}
