/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:14:37 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/19 13:14:39 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * move_keys:
 * This function is called to adjust the position of the figure.
 * 
 */
int	move_keys(int key, t_inf *info)
{
	if (key == A)
		info->slide_x += 10;
	if (key == S)
		info->slide_y -= 10;
	if (key == D)
		info->slide_x -= 10;
	if (key == W)
		info->slide_y += 10;
	return (1);
}

/**
 * change_perspective:
 * This function is called to change the perspective of the figure.
 * 
 */
int	change_perspective(int key, t_inf *info)
{
	if (key == P)
	{
		if (info->persp == RAD_30)
			info->persp = RAD_10;
		else
			info->persp = RAD_30;
	}
	return (1);
}

/**
 * key_press:
 * This function is called when some key is pressed.
 * 
 */
int	key_press(int key, t_inf *info)
{
	int	refresh;

	refresh = 0;
	if (key == ESC || key == ESC_LINUX)
		free_paint(info, NULL);
	if (key == PLUS)
	{
		info->multiplier++;
		refresh = 1;
	}
	if (key == MINUS && info->multiplier > 0)
	{
		info->multiplier--;
		refresh = 1;
	}
	if (key == P)
		refresh = change_perspective(key, info);
	if (key == A || key == S || key == D || key == W)
		refresh = move_keys(key, info);
	if (refresh)
		create_window(info);
	return (0);
}

/**
 * close_fdf:
 * This function is called when x is pressed to close the window.
 * 
 */
int	close_fdf(t_inf *info)
{
	free_paint(info, NULL);
	return (0);
}

/**
 * set_hook:
 * This function is called to set up the hooks.
 * 
 */
void	set_hook(t_inf *info)
{
	mlx_hook(info->window, MLX_KEY_PRESS, MLX_KEY_PRESS_MASK, key_press, info);
	mlx_hook(info->window, DESTROYNOTIFY, 0, close_fdf, info);
}
