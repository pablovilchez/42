/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:07:50 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/21 23:43:40 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_line_h(t_axis pos_a, t_axis pos_b, mlx_image_t *image)
{
	int	x;
	int	y;
	int	count;
	int	step;

	count = 0;
	x = pos_a.x;
	while (x < pos_b.x)
	{
		step = count * (pos_b.y - pos_a.y) / (pos_b.x - pos_a.x);
		y = pos_a.y + step;
		mlx_put_pixel(image, x, y, 0x00FFFFFF);
		x++;
		count++;
	}
}

void	new_line_v(t_axis pos_a, t_axis pos_b, mlx_image_t *image)
{
	int	x;
	int	y;
	int	count;
	int	step;

	count = 0;
	y = pos_a.y;
	while (y < pos_b.y)
	{
		step = count * (pos_b.x - pos_a.x) / (pos_b.y - pos_a.y);
		x = pos_a.x + step;
		mlx_put_pixel(image, x, y, 0x00FFFFFF);
		y++;
		count++;
	}
}

void	print_lines(t_vertex **matrix, int *size, mlx_image_t *image)
{
	int			x;
	int			y;

	y = 0;
	while (y < size[1])
	{
		x = 0;
		while (x < size[0])
		{
			if (x + 1 < size[0])
				new_line_h(matrix[y][x].dest, matrix[y][x + 1].dest, image);
			if (y + 1 < size[1])
				new_line_v(matrix[y][x].dest, matrix[y + 1][x].dest, image);
			x++;
		}
		y++;
	}
}

void	error_exit(mlx_t *mlx)
{
	mlx_close_window(mlx);
	puts(mlx_strerror(mlx_errno));
}

int32_t	print_matrix(t_vertex **matrix, int *size)
{
	static mlx_image_t	*image;
	mlx_t				*mlx;

	mlx = mlx_init(800, 800, "FdF", true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	image = mlx_new_image(mlx, 800, 800);
	if (!image)
	{
		error_exit(mlx);
		return (EXIT_FAILURE);
	}
	print_lines(matrix, size, image);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		error_exit(mlx);
		return (EXIT_FAILURE);
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
