/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:42:23 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/19 19:21:56 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	if (check_file(argc, argv))
		ft_printf("El archivo tiene formato correcto.");
	else
		ft_printf("Archivo no válido.");
	return (0);
}
