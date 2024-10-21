/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:51:22 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/21 18:17:20 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_isfractal(char *s)
{
	if (!ft_strcmp(s, Frac1))
		return (1);
	else if(!ft_strcmp(s, Frac2))
		return (2);
	else if (!ft_strcmp(s, Frac3))
		return (3);
	else if (!ft_strcmp(s,  Frac4))
		return (4);
	else if (!ft_strcmp(s, Frac5))
		return (5);
	else if (!ft_strcmp(s, Frac6))
		return (6);
	else
		return (0);
}

void	error_mlx(char *model)
{
	ft_printf("%s: %s: init mlx error\n");
	exit (1);
}

void	error_args(void)
{
	ft_printf("%s: Wrong input\n");
	ft_printf("\t -%s\n\t- %s\n\t- %s\n\t- %s\n\t- %s\n, \
		Frac1, Frac2, Frac3, Frac4, Frac5, Frac6");
	exit (2);
}
	
