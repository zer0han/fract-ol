/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:44:20 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/25 20:07:09 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static double	ft_power(double base, int power, double output)
{
	if (power < 0)
		return (0.0);
	if (!power)
		return (output);
	else
		return (ft_power(base, power - 1, output * base));
}

static void	ft_handler(double *nbr, int i, const char *nptr)
{
	int	j;

	j = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		*nbr = *nbr + (nptr[i] - '0') * ft_power(0.1, j++, 1);
		i++;
	}
}

double	ft_atof(const char *nptr)
{
	int		i;
	double	sign;
	double	nbr;

	i = 0;
	sign = 1.0;
	nbr = 0.0;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = ((nbr * 10) + (nptr[i] - '0'));
		i++;
	}
	if (nptr[i] == '.')
		ft_handler (&nbr, ++i, nptr);
	return (nbr * sign);
}
