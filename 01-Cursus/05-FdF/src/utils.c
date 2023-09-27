/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:16:12 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/24 20:57:25 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pix_num(t_vertex *v_a, t_vertex *v_b, t_diff diff)
{
	int		current_x;
	int		current_y;
	int		err2;
	int		count;

	count = 0;
	current_x = v_a->dest.x;
	current_y = v_a->dest.y;
	while (current_x != v_b->dest.x || current_y != v_b->dest.y)
	{
		count++;
		err2 = 2 * diff.err;
		if (err2 > -diff.dy)
		{
			diff.err -= diff.dy;
			current_x += diff.sx;
		}
		if (err2 < diff.dx)
		{
			diff.err += diff.dx;
			current_y += diff.sy;
		}
	}
	count++;
	return (count);
}

int	count_pix(t_vertex *vertex_a, t_vertex *vertex_b)
{
	t_diff	diff;

	diff.dx = abs(vertex_b->dest.x - vertex_a->dest.x);
	diff.dy = abs(vertex_b->dest.y - vertex_a->dest.y);
	if (vertex_a->dest.x < vertex_b->dest.x)
		diff.sx = 1;
	else
		diff.sx = -1;
	if (vertex_a->dest.y < vertex_b->dest.y)
		diff.sy = 1;
	else
		diff.sy = -1;
	diff.err = diff.dx - diff.dy;
	return (pix_num(vertex_a, vertex_b, diff));
}
