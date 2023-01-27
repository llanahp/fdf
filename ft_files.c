/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:36:36 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/19 19:36:38 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/** open_input:
 * This function opens the file that is going to be use as an input.
 * If something went wrong, the program display an error message and exit
 * 
 */
void	open_input(t_inf *info)
{
	info->in_file = open (info->argv[1], O_RDONLY, 644);
	if (info->in_file < 0)
		msg_error("Error trying to open file");
}
