/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:52:07 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/13 10:52:09 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_content_split(void *string)
{
	if (string != NULL)
		free(string);
}

void	ft_split_clear(char **split, void (*del)(void*))
{
	int		i;

	i = -1;
	if (del == NULL)
		del = &free_content_split;
	if (del != NULL && split != NULL)
	{
		while (split[++i])
		{
			free(split[i]);
		}
		free(split);
	}
}
