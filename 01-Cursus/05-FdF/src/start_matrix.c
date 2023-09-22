/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:18:29 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/22 13:16:38 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_isometric(t_vertex **matrix, int rows)
{
	int		x;
	int		y;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < matrix[y][x].len)
		{
			matrix[y][x].dest.x = matrix[y][x].start.x;
			matrix[y][x].dest.y = matrix[y][x].start.y - matrix[y][x].high;
			x++;
		}
		y++;
	}
}

void	line_len(t_vertex *matrix_line, int line_len)
{
	int		x;

	x = 0;
	while (x < line_len)
	{
		matrix_line[x].len = line_len;
		x++;
	}
}

void	start_matrix(t_vertex **matrix, int rows)
{
	t_axis	start;
	int		margin;
	int		x;
	int		y;

	start.x = 100;
	start.y = 100;
	margin = 30;
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < matrix[y][x].len)
		{
			matrix[y][x].start.x = start.x + x * margin + y * 10;
			matrix[y][x].start.y = start.y + y * margin / 2;
			matrix[y][x].color = 0xFFFFFFFF;
			x++;
		}
		y++;
	}
	make_isometric(matrix, rows);
}
