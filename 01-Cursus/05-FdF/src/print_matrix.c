/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:07:50 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/21 00:05:22 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_matrix(t_vertex **matrix, int *size)
{
	int	x;
	int	y;

	ft_printf("Valor de x: %i     Valor de y: %i\n", size[0], size[1]);
	y = 0;
	while (y < size[1])
	{
		x = 0;
		while (x < size[0])
		{
			ft_printf(" %i ", matrix[y][x].high);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

/*
while (matrix[y])
	{
		x = 0;
		while (&matrix[y][x])
		{
			ft_printf(" %i ", matrix[y][x].high);
			x++;
		}
		ft_printf("\n");
		y++;
	}
*/
