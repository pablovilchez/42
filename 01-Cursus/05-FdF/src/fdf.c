/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:42:23 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/27 22:24:15 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_vertex	**matrix;
	t_mmsizes	mmsizes;
	int			rows;

	matrix = get_matrix(argc, argv, &rows);
	start_matrix(matrix, &rows, &mmsizes);
	print_matrix(matrix, &rows, &mmsizes);
	free_matrix(matrix, &rows);
	return (0);
}
