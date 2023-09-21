/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:42:23 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/21 12:10:43 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_vertex	**matrix;
	int			size[2];

	matrix = get_matrix(argc, argv, size);
	start_matrix(matrix, size);
	print_matrix(matrix, size);
	return (0);
}
