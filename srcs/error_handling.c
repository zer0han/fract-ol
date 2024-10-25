/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:51:22 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/25 19:08:52 by rdalal           ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
}

int	ft_isfractal(char *s)
{
	if (!ft_strcmp(s, F1))
		return (1);
	else if (!ft_strcmp(s, F2))
		return (2);
	else if (!ft_strcmp(s, F3))
		return (3);
	else if (!ft_strcmp(s, F4))
		return (4);
	else if (!ft_strcmp(s, F5))
		return (5);
	else if (!ft_strcmp(s, F6))
		return (6);
	else
		return (0);
}

void	error_mlx(char *model)
{
	ft_printf("%s: %s: init mlx error\n", P_NAME, model);
	exit (1);
}

void	error_args(void)
{
	ft_printf("%s: Wrong input stupid\n");
	ft_printf("\t -%s\n\t- %s\n\t- %s\n\t- %s\n\t- %s\n, \
		F1, F2, F3, F4, F5, F6");
	exit (2);
}
