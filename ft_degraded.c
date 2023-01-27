/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degraded.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:37:36 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/19 19:37:38 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/****
 * percent:
 * This function calculates the percentage of a value (current) between 
 *  a start value and an end value.
 * 
 * It takes three integer parameters (start, end, and current) 
 *  and returns a double.
 *
 * It calculates the percentage by finding the placement of the current value
 *  between the start and end values by subtracting start from current 
 *  and then divides this value by the distance between the start and end values.
 * 
 * If the distance is zero it returns 1.0.
 * 
*/
double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

/**
 * get_percentage:
 * This function calculates the percentage of color to use according
 * 	to the increment of x and y.
 * 
 */
double	get_percentage(t_inf *info, t_point start, t_point end, t_point actual)
{
	double	percentage;

	if (info->dx > info->dy)
		percentage = percent(start.x, end.x, actual.x);
	else
		percentage = percent(start.y, end.y, actual.y);
	return (percentage);
}
