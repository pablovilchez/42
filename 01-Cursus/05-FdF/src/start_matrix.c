/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:18:29 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/22 16:48:55 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_isometric(t_vertex **matrix, int *rows)
{
	int		x;
	int		y;

	y = 0;
	while (y < *rows)
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

void	line_len(t_vertex *matrix_line, int total_x)
{
	int		x;

	x = 0;
	while (x < total_x)
	{
		matrix_line[x].len = total_x;
		x++;
	}
}

void	start_matrix(t_vertex **matrix, int *rows)
{
	t_axis	start;
	int		margin;
	int		x;
	int		y;

	ft_printf("%i\n", matrix[0][0].len - 1);
	start.x = 100;
	start.y = 100;
	margin = 30;
	y = 0;
	while (y < *rows)
	{
		x = 0;
		ft_printf("ok 1\n");
		ft_printf("%i\n", matrix[y][x].len);
		ft_printf("ok 1\n");
		while (x < matrix[y][x].len)
		{
			ft_printf("ok 2");
			matrix[y][x].start.x = start.x + x * margin + y * 10;
			matrix[y][x].start.y = start.y + y * margin / 2;
			matrix[y][x].color = 0xFFFFFFFF;
			x++;
		}
		y++;
	}
	make_isometric(matrix, rows);
}
