/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:33:19 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/27 23:33:50 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reduce_size(t_vertex **matrix, int *rows, int factor)
{
	int	x;
	int	y;
	int	lenght;

	y = 0;
	ft_printf("   factor: %i\n", factor);
	ft_printf("valor de 2,2   x: %i   y: %i\n", matrix[2][2].dest.x, matrix[2][2].dest.y);
	while (y < *rows)
	{
		x = 0;
		lenght = matrix[y][x].len;
		while (x < lenght)
		{
			matrix[y][x].dest.x *= 100;
			matrix[y][x].dest.x /= factor;
			matrix[y][x].dest.y *= 100;
			matrix[y][x].dest.y /= factor;
			matrix[y][x].high *= 100;
			matrix[y][x].high /= factor;
			x++;
		}
		y++;
	}
	ft_printf("valor de 2,2   x: %i   y: %i\n", matrix[2][2].dest.x, matrix[2][2].dest.y);
	ft_printf("sale de reduce_size\n");
}

void	calc_img_size(t_mmsizes *mmsizes, t_vertex **matrix, int *rows)
{
	ft_printf("   max_x: %i   max_y: %i\n", mmsizes->max_x, mmsizes->max_y);
	if (mmsizes->max_x / 1400 > mmsizes->max_y / 800)
	{
		ft_printf("entra por x\n");
		reduce_size(matrix, rows, mmsizes->max_x * 100 / 1400);
	}
	else
	{
		ft_printf("entra por y\n");
		reduce_size(matrix, rows, mmsizes->max_y * 100 / 800);
	}
}

void	calc_maxims(t_vertex **matrix, int *rows, t_mmsizes *mmsizes)
{
	int	x;
	int	y;
	int	lenght;

	y = 0;
	while (y < *rows)
	{
		x = 0;
		lenght = matrix[y][x].len;
		while (x < lenght)
		{
			if (matrix[y][x].dest.x > mmsizes->max_x)
				mmsizes->max_x = matrix[y][x].dest.x;
			if (matrix[y][x].dest.y > mmsizes->max_y)
				mmsizes->max_y = matrix[y][x].dest.y;
			x++;
		}
		y++;
	}
}

void	calc_minims(t_vertex **matrix, int *rows, t_mmsizes *mmsizes)
{
	int	x;
	int	y;
	int	lenght;

	y = 0;
	while (y < *rows)
	{
		x = 0;
		lenght = matrix[y][x].len;
		while (x < lenght)
		{
			if (matrix[y][x].dest.x < mmsizes->min_x)
				mmsizes->min_x = matrix[y][x].dest.x;
			if (matrix[y][x].dest.y < mmsizes->min_y)
				mmsizes->min_y = matrix[y][x].dest.y;
			x++;
		}
		y++;
	}
	if (mmsizes->min_x < 0)
		mmsizes->min_x *= -1;
	if (mmsizes->min_y < 0)
		mmsizes->min_y *= -1;
}

void	adjust_values(t_vertex **matrix, int *rows, t_mmsizes *mmsizes)
{
	int	x;
	int	y;
	int	lenght;

	mmsizes->min_x = 0;
	mmsizes->min_y = 0;
	calc_minims(matrix, rows, mmsizes);
	y = 0;
	while (y < *rows)
	{
		x = 0;
		lenght = matrix[y][x].len;
		while (x < lenght)
		{
			matrix[y][x].dest.x += mmsizes->min_x;
			matrix[y][x].dest.y += mmsizes->min_y;
			x++;
		}
		y++;
	}
	calc_maxims(matrix, rows, mmsizes);
}