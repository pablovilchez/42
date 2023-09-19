/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:41:03 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/20 00:17:12 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**nodelst_to_matrix(t_node **nodelst)
{
	int		**matrix;
	t_node	*node;
	int		line;
	int		len;
	int		aux;

	line = 0;
	len = 0;
	aux = 0;
	if (check_size(nodelst) && *matrix != NULL)
	{
		node = *nodelst;
		while (node)
		{
			node = node->next;
		}
	}
	return (NULL);
}
