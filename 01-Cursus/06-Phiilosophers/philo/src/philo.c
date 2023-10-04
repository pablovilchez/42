/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:10:59 by pvilchez          #+#    #+#             */
/*   Updated: 2023/10/04 23:36:06 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_table			table;
	pthread_mutex_t	*forks;

	if (capt_args(argc, argv, &table))
	{
		print_table(table);
		if (create_mutex(&table, forks) == 0)
		{
			start_philos(&table);
			destroy_mutex(&table);
		}
	}
	return (0);
}
