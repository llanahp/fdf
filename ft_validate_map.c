/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:47:26 by ralopez-          #+#    #+#             */
/*   Updated: 2023/01/19 19:47:27 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/***
 * adjust_multiplier:
 * This function modify how close the figure is going to be dependding 
 * the length of the line.
 * 
*/
void	adjust_multiplier(t_inf *info)
{
	if (info->x < 30)
		info->multiplier = 20;
	else if (info->x < 110)
		info->multiplier = 15;
	else if (info->x < 170)
		info->multiplier = 10;
	else if (info->x < 230)
		info->multiplier = 5;
	else
		info->multiplier = 3;
}

/**
 * validate_position:
 * This function is called for every cell in a row.
 * 
 * They verifies if contains the value for the point and, in some cases,
 * 	the color 
 * 
 * Returns the string where they has ended
*/
char	*validate_position(char	*line)
{
	if (*line == '-' || *line == '+')
		line++;
	while (*line && *line != ' ' && *line != ',')
	{
		if (*line < '0' || *line > '9')
			return (NULL);
		line++;
	}
	if (*line == ',')
	{
		if (*(line + 1) != '0' || *(line + 2) != 'x')
			return (NULL);
		line = line + 3;
		while (*line && *line != ' ')
		{
			if ((*line < '0' || *line > '9') && (*line < 'a' || *line > 'f')
				&& (*line < 'A' || *line > 'F'))
				return (NULL);
			line++;
		}
	}
	return (line);
}

/**
 * check_line:
 * This function is called for each line in the file.
 * They skips the spaces and calls 'validate_position' to validate the cell
 * 
 * Returns -1 if something is wrong
 * 
 * Return 0 if all went correctly
 */
int	check_line(char *line, t_inf *info)
{
	int	x;

	x = 0;
	while (*line)
	{
		while (*line == ' ')
			line++;
		line = validate_position(line);
		if (line == NULL)
			return (-1);
		while (*line == ' ')
			line++;
		x++;
	}
	if (info->x != 0 && info->x != x)
		return (-1);
	info->x = x;
	return (0);
}

/**
 * correct_extension:
 * This function validates the extension of a file.
 * 
 */
int	correct_extension(char *string, char *extension)
{
	char	*ext;
	int		result;

	ext = ft_substr(string, ft_strlen(string) - 4, 4);
	result = ft_strcmp(ext, extension) != 0;
	free(ext);
	if (result)
		return (-1);
	else
		return (0);
}

/***
 * validate_input:
 * This function validates if the map is correct.
 * If it is, stores it in info->map
 * 
 * If the map have something wrong, displays a error message
 * 	and exit whith status code 0
 */
void	validate_input(t_inf *info)
{
	char	*line;
	char	**cnt_line;

	if (correct_extension(info->argv[1], ".fdf") == -1)
		msg_error("Error extension map not valid");
	open_input(info);
	line = get_next_line(info->in_file);
	while (line != NULL)
	{
		if (ft_strlen(line) > 1 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (check_line(line, info) == -1)
			msg_error("Error map not valid");
		cnt_line = ft_split(line, ' ');
		if (!cnt_line)
			msg_error("Error split line");
		if (store_line(cnt_line, info) == -1)
			msg_error("Error stroring map line");
		info->y++;
		free(line);
		free_split(cnt_line);
		line = get_next_line(info->in_file);
	}
	info->y--;
	close(info->in_file);
}
