/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:01:58 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/21 19:13:46 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(t_vertex **matrix, int *size)
{
	int	y;

	y = 0;
	while (y < size[1])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}
