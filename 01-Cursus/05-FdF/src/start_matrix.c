/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:18:29 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/21 23:54:31 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_isometric(t_vertex **matrix, int *size)
{
	int		x;
	int		y;

	y = 0;
	while (y < size[1])
	{
		x = 0;
		while (x < size[0])
		{
			matrix[y][x].dest.x = matrix[y][x].start.x;
			matrix[y][x].dest.y = matrix[y][x].start.y;
			x++;
		}
		y++;
	}
}


void	start_matrix(t_vertex **matrix, int *size)
{
	t_axis	start;
	int		margin;
	int		x;
	int		y;

	start.x = 100;
	start.y = 100;
	margin = 30;
	y = 0;
	while (y < size[1])
	{
		x = 0;
		while (x < size[0])
		{
			matrix[y][x].start.x = start.x + x * margin;
			matrix[y][x].start.y = start.y + y * margin;
			x++;
		}
		y++;
	}
	make_isometric(matrix, size);
}
