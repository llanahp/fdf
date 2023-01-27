/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:47:14 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/19 19:47:15 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/***
 * hex_to_int:
 * This function converts a hexadecimal string to an integer. 
 * The conversion process is done through the use of a loop that goes through 
 *	each character of the string, determining its corresponding decimal value 
 *  and accumulating in a "result" variable the product of that value by 16 
 *  raised to the power of its position in the string.
 * 
 * Returns the result of the conversion.
 */
int	hex_to_int(char *hex)
{
	int	i;
	int	result;
	int	number;

	i = -1;
	result = 0;
	number = 0;
	while (++i < (int)ft_strlen(hex))
	{
		if (hex[i] >= 'a' && hex[i] <= 'z')
			number = hex[i] - 87;
		else if (hex[i] >= 'A' && hex[i] <= 'Z')
			number = hex[i] - 55;
		else
			number = hex[i] - 48;
		result += (pow(16, i) * number);
	}
	return (result);
}

/***
 * get_point:
 * This function populates a t_point struct with information from a string.
 * It sets the value field to the integer representation of the string, 
 * and uses the set_color function to get the color field. 
 * 
 * If no comma is found, sets the color field to default value.
 *
*/
void	get_point(char *string, t_point *point)
{
	point->value = ft_atoi(string);
	while (*string && *string != ',')
		string++;
	if (*string == ',')
	{
		string++;
		point->color = set_color(string);
	}
	else
		point->color = 0xFFFFFF;
}

/***
 * add_line:
 * This function adds a line of information to a 2D array of t_point structs.
 * It allocates memory for the new line, and populates each t_point struct in
 *  the line with the appropriate information using the "get_point" function.
 * 
 * Returns the new array.
 * 
*/
t_point	*add_line(char **line, t_inf *info)
{
	int		i;
	t_point	*new;

	i = 0;
	new = (t_point *)ft_calloc(info->x + 1, sizeof(t_point));
	if (!new)
		return (NULL);
	while (line[i] != NULL)
	{
		get_point(line[i], &new[i]);
		new[i].x = i;
		new[i].y = info->y;
		i++;
	}
	return (new);
}

/**
 * store_line:
 * This function stores a line of information in a struct, 
 *   using a 2D array of t_point structs. 
 *   It allocates memory for the array , adds the current line, and if necessary,
 *   copies over previous map and frees it. 
 * 
 * Returns 0 at the end.
*/
int	store_line(char **line, t_inf *info)
{
	int		i;
	t_point	**temp;

	temp = (t_point **)ft_calloc(info->y + 2, sizeof(t_point *));
	if (!temp)
		msg_error("Error in malloc");
	i = info->y;
	temp[i] = add_line(line, info);
	if (!temp[i])
		msg_error("Error in malloc");
	if (info->map != NULL)
	{
		i--;
		while (i >= 0)
		{
			temp[i] = (t_point *) info->map[i];
			i--;
		}
		free(info->map);
	}
	info->map = temp;
	return (0);
}

/**
 * free_map:
 * This function frees all memory of the map
 * 
 */
void	free_map(t_inf *info)
{
	int	i;

	i = 0;
	while ((info->map[i] != NULL))
	{
		free(info->map[i]);
		i++;
	}
	if (info->map != NULL)
		free(info->map);
	info->map = NULL;
}
