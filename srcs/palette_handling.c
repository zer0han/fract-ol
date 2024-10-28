/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:01:16 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/25 22:08:27 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	pal_1(int i)
{
	if (i % 8 == 0)
		return (make_rgbt(0, 76, 153, 23));
	else if (i % 8 == 1)
		return (make_rgbt(102, 102, 255, 57));
	else if (i % 8 == 2)
		return (make_rgbt(255, 51, 153, 220));
	else if (i % 8 == 3)
		return (make_rgbt(153, 243, 20, 130));
	else if (i % 8 == 4)
		return (make_rgbt(153, 153, 255, 150));
	else if (i % 8 == 5)
		return (make_rgbt(0, 0, 153, 42));
	else if (i % 8 == 6)
		return (make_rgbt(157, 246, 240, 98));
	else
		return (make_rgbt(102, 0, 204, 198));
}

static int	pal_2(int i)
{
	if (i % 4 == 0)
		return (make_rgbt(250, 112, 112, 100));
	else if (i % 4 == 1)
		return (make_rgbt(254, 253, 237, 200));
	else if (i % 4 == 2)
		return (make_rgbt(198, 235, 197, 130));
	else
		return (make_rgbt(161, 195, 152, 110));
}

static int	pal_3(int i)
{
	if (i % 5 == 0)
		return (make_rgbt(229, 61, 0, 120));
	else if (i % 5 == 1)
		return (make_rgbt(255, 233, 0, 230));
	else if (i % 5 == 2)
		return (make_rgbt(252, 255, 247, 160));
	else if (i % 5 == 3)
		return (make_rgbt(33, 160, 160, 170));
	else
		return (make_rgbt(4, 104, 101, 180));
}

int	get_pal(int i, int pal_no)
{
	if (pal_no == 2)
		return (pal_2(i));
	else if (pal_no == 3)
		return (pal_3(i));
	return (pal_1(i));
}

/*int get_pal(int i)
{
    int index = i % 8; // Adjust the modulo value based on your palette size
    int next_index = (index + 1) % 8;

    // Get the colors for the current and next index
    int color1 = pal_1(index);
    int color2 = pal_1(next_index);

    // Calculate the interpolation factor based on the fractional part of i/8
    double f = i / 8.0 - floor(i / 8.0);

    // Interpolate the colors
    int r = (int)(f * get_color(color2, 'r') + (1 - f) * get_color(color1, 'r'));
    int g = (int)(f * get_color(color2, 'g') + (1 - f) * get_color(color1, 'g'));
    int b = (int)(f * get_color(color2, 'b') + (1 - f) * get_color(color1, 'b'));
    int t = (int)(f * get_color(color2, 't') + (1 - f) * get_color(color1, 't'));

    return (make_rgbt(r, g, b, t));
}
*/
