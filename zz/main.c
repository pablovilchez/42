/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:30:08 by pvilchez          #+#    #+#             */
/*   Updated: 2023/10/01 19:58:23 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t miMutex;

int	contador = 0;

void	*miFuncion(void *arg)
{
	int	tid;
	int	hilo;

	hilo = *((int *)arg);
	tid = (int)pthread_self();
	for (int i = 0; i < 10; i++) {
		pthread_mutex_lock(&miMutex);
		if (pthread_equal(tid, hilo))
			printf("imprime A\n");
		if (pthread_equal(tid, hilo))
			printf("   imprime B\n");
		contador++;
		pthread_mutex_unlock(&miMutex);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	hilos[2];

	if (pthread_mutex_init(&miMutex, NULL) != 0)
	{
		perror("Error al inicializar el mutex");
		return (1);
	}
	for (int i = 0; i < 2; i++)
	{
		if (pthread_create(&hilos[i], NULL, miFuncion, &hilos[i]) != 0)
		{
			perror("Error al crear el hilo");
			return (1);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (pthread_join(hilos[i], NULL) != 0)
		{
			perror("Error al unir el hilo");
			return (1);
		}
	}
	pthread_mutex_destroy(&miMutex);
	printf("Valor final del contador: %d\n", contador);
	return (0);
}
