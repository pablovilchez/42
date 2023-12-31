/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:39:21 by pvilchez          #+#    #+#             */
/*   Updated: 2023/09/18 19:09:38 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, unsigned int n)
{
	unsigned int	i;
	char			*p;

	i = 0;
	p = (char *)str;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (p);
}

/*
int	main(void)
{
	char	str[50];
	char	str2[50];
	int		i;

	strcpy(str, "This is string.h library function");
	puts(str);
	i = 0;
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	memset(str, '$', 7);
	puts(str);
	ft_memset(str2, '$', 7);
	puts(str2);
	return (0);
}
*/