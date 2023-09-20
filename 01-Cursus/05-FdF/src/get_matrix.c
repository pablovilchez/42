/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:53:00 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/21 00:08:01 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_size_error(int y, int total_x, int *s_err, int *size)
{
	static int	num;

	if (y == 0)
	{
		num = total_x;
		size[0] = num;
	}
	else if (total_x != num)
		*s_err = 1;
}

t_vertex	**lines_to_vertex(char **lines, int total_y, int *s_err, int *size)
{
	int			y;
	int			total_x;
	t_vertex	**matrix;
	char		**line;

	y = 0;
	matrix = (t_vertex **)ft_calloc(total_y, sizeof(t_vertex *));
	while (lines[y])
	{
		line = ft_split(lines[y], ' ');
		total_x = 0;
		while (line[total_x])
			total_x++;
		matrix[y] = (t_vertex *)ft_calloc(total_x, sizeof(t_vertex));
		check_size_error(y, total_x, s_err, size);
		total_x = 0;
		while (line[total_x])
		{
			matrix[y][total_x].high = ft_atoi(line[total_x]);
			total_x++;
		}
		y++;
		ft_free_lst(line);
	}
	return (matrix);
}

t_vertex	**text_to_matrix(char *get_text, int *s_err, int *size)
{
	char		**lines;
	int			total_y;
	t_vertex	**matrix;

	total_y = 0;
	lines = ft_split(get_text, '\n');
	while (lines[total_y])
		total_y++;
	size[1] = total_y;
	matrix = lines_to_vertex(lines, total_y, s_err, size);
	ft_free_lst(lines);
	return (matrix);
}

char	*file_to_str(int filefd)
{
	char	*get_text;
	char	*buffer;

	get_text = (char *)ft_calloc(1, sizeof(char));
	buffer = ft_get_next_line(filefd);
	while (buffer)
	{
		get_text = ft_strjoin(get_text, buffer);
		free(buffer);
		buffer = ft_get_next_line(filefd);
	}
	return (get_text);
}

t_vertex	**get_matrix(int argc, char *argv[], int *size)
{
	int			filefd;
	char		*get_text;
	t_vertex	**matrix;
	int			s_err;

	s_err = 0;
	if (argc != 2)
		ft_printf("Error: bad arguments.");
	else
	{
		filefd = open(argv[1], O_RDONLY, 0777);
		if (filefd == -1)
			ft_printf("Error opening file.");
		else
		{
			get_text = file_to_str(filefd);
			close(filefd);
			matrix = text_to_matrix(get_text, &s_err, size);
			if (s_err == 0)
				return (matrix);
			//TODO liberar matrix si error
		}
	}
	return (NULL);
}
