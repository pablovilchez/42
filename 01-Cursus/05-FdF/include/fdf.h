/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:40:09 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/22 16:42:00 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "../assets/libft/include/libft.h"
#include "../assets/MLX42/include/MLX42/MLX42.h"

typedef struct s_xy_start
{
	int				x;
	int				y;
}					t_axis;

typedef struct s_vertex
{
	int				high;
	int				len;
	uint32_t		color;
	t_axis			start;
	t_axis			dest;
}					t_vertex;

// get_matrix.c
t_vertex	**get_matrix(int argc, char *argv[], int *rows);
char		*file_to_str(int filefd);
t_vertex	**text_to_matrix(char *get_text, int *rows);
t_vertex	**lines_to_vertex(char **lines, int total_y);
int			count_elements(char **line);
// start_matrix.c
void		make_isometric(t_vertex **matrix, int *rows);
void		line_len(t_vertex *matrix_line, int line_len);
void		start_matrix(t_vertex **matrix, int *rows);
// capture_color.c
//void		capture_color(char *line, uint32_t *color);
// print_matrix.c
int32_t		print_matrix(t_vertex **matrix, int *rows);
void		error_exit(mlx_t *mlx);
void		print_lines(t_vertex **matrix, int *rows, mlx_image_t *image);
void		new_line_v(t_axis pos_a, t_axis pos_b, mlx_image_t *image);
void		new_line_h(t_axis pos_a, t_axis pos_b, mlx_image_t *image);
// free_matrix.c
void		free_matrix(t_vertex **matrix, int *rows);
