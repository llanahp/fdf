/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:58:54 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/17 12:58:56 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * msg_error:
 * Displays a message and ends the program
 * 
 */
void	msg_error(char *msg)
{
	if (msg != NULL)
		ft_printf("%s\n", msg);
	exit(0);
}

/**
 * free_split:
 * This function desalocates the memory inside of a split.
 * It also desalocates the split itselfs.
*/
void	free_split(char **content)
{
	int	i;

	i = -1;
	while (content[++i] != NULL)
	{
		free(content[i]);
	}
	free(content);
	content = NULL;
}

/**
 * free_paint:
 * This function frees all memory and display a message.
 * 
 */
int	free_paint(t_inf *info, char *msg_err)
{
	if (info != NULL)
	{
		if (info->img.img != NULL)
			mlx_destroy_image(info->mlx, info->img.img);
		if (info->window != NULL)
			mlx_destroy_window(info->mlx, info->window);
	}
	msg_error(msg_err);
	return (-1);
}
