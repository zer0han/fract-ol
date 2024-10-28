/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:32:38 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/24 17:58:41 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	make_rgbt(int r, int g, int b, int t)
{
	return (r << 16 | g << 8 | b | t << 24);
}

int	get_color(int rgbt, char i)
{
	if (i == 'r')
		return ((rgbt >> 16) & 0xFF);
	else if (i == 'g')
		return ((rgbt >> 8) & 0xFF);
	else if (i == 'b')
		return (rgbt & 0xFF);
	else
		return ((rgbt >> 24) & 0xFF);
}

int	add_shade(double f, int color)
{
	int	new_t;
	int	new_r;
	int	new_g;
	int	new_b;

	new_t = get_color(color, 't');
	new_r = get_color(color, 'r') * (1 - f);
	new_g = get_color(color, 'g') * (1 - f);
	new_b = get_color(color, 'b') * (1 - f);
	return (make_rgbt(new_r, new_g, new_b, new_t));
}

int	get_opp(int color)
{
	int	new_t;
	int	new_r;
	int	new_g;
	int	new_b;

	new_t = get_color(color, 't');
	new_r = 255 + get_color(color, 'r');
	new_g = 255 + get_color(color, 'g');
	new_b = 255 + get_color(color, 'b');
	return (make_rgbt(new_r, new_g, new_b, new_t));
}
