/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:53:00 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/20 00:37:01 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_elem(char **split_line)
{
	int	line_elem;

	line_elem = 0;
	while (split_line[line_elem])
		line_elem++;
	return (line_elem);
}

int	split_line(char *line, int y, t_node **nodelst)
{
	t_node	*node;
	char	**split_line;
	int		x;
	int		line_elem;

	x = 0;
	split_line = ft_split(line, ' ');
	line_elem = count_elem(split_line);
	while (split_line[x])
	{
		node = ft_lstnew(ft_atoi(split_line[x]), x, y);
		ft_lstadd_back(nodelst, node);
		x++;
	}
	ft_free_lst(split_line);
	return (line_elem);
}

int	text_to_nodelst(char *get_text, t_node **nodelst)
{
	char	**line;
	int		y;
	int		line_elem;
	int		max;

	y = 0;
	line = ft_split(get_text, '\n');
	while (line[y])
	{
		line_elem = split_line(line[y], y, nodelst);
		if (max == 0)
			max = line_elem;
		if (max != line_elem)
		{
			ft_free_lst(line);
			return (1);
		}
		y++;
	}
	ft_free_lst(line);
	return (0);
}

char	*file_to_str(int filefd)
{
	char	*get_text;
	char	*buffer;

	get_text = NULL;
	buffer = ft_get_next_line(filefd);
	while (buffer)
	{
		ft_strjoin(get_text, buffer);
		free(buffer);
		buffer = ft_get_next_line(filefd);
	}
	close(filefd);
	return (get_text);
}

int	**get_matrix(int argc, char *argv[])
{
	int		**matrix;
	int		filefd;
	char	*get_text;
	t_node	**nodelst;

	if (argc != 2)
		ft_printf("Error: bad arguments.");
	else
	{
		filefd = open(argv[1], O_RDONLY, 0777);
		if (filefd == -1)
			return (1);
		get_text = file_to_str(filefd);
		if (text_to_nodelst(get_text, nodelst) == 0)
			matrix = nodelst_to_matrix(nodelst);
		ft_lstclear(nodelst);
		return (matrix);
	}
	return (NULL);
}
