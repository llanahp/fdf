/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:14:39 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/14 17:18:54 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * main:
 * This function is the main function of the program.
 * Validates the map input and draws it.
 * 
 */
int	main(int argc, char **argv)
{
	t_inf	info;

	if (argc != 2)
	{
		ft_printf("Error : Number of arguments not valid\n");
		ft_printf("Example: \n\t./fdf 42.fdf\n");
		return (0);
	}
	ft_bzero(&info, sizeof(t_inf));
	info.argc = argc;
	info.argv = argv;
	info.slide_x = 0;
	info.slide_y = 0;
	info.persp = RAD_30;
	validate_input(&info);
	adjust_multiplier(&info);
	return (set_up_mlx(&info));
}
