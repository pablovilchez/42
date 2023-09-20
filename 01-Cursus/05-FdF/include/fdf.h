/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:40:09 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/21 00:02:41 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "../assets/libft/include/libft.h"
#include "../assets/MLX42/include/MLX42/MLX42.h"

// fdf.c
t_vertex	**get_matrix(int argc, char *argv[], int *size);
// print_matrix.c
void		print_matrix(t_vertex **matrix, int *size);