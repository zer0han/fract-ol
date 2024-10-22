/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:01:16 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/22 17:25:40 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	pal_1(int i)
{
	if (i % 8 == 0)
		return (make_rgbt(133, 50, 33, 0));
	else if (i % 8 == 1)
		return (make_rgbt(254, 94, 65, 0));
	else if (i % 8 == 2)
		return (make_rgbt(249, 144, 93, 0));
	else if (i % 8 == 3)
		return (make_rgbt(243, 193, 120, 0));
	else if (i % 8 == 4)
		return (make_rgbt(230, 217, 140, 0));
	else if (i % 8 == 5)
		return (make_rgbt(216, 241, 160, 0));
	else if (i % 8 == 6)
		return (make_rgbt(0, 168, 120, 0));
}

static int	pal_2(int i)
{
	if (i % 4 == 0)
		return (make_rgbt(250, 112, 112, 0));
	else if (i % 4 == 1)
		return (make_rgbt(254, 253, 237, 0));
	else if (i % 4 == 2)
		return (make_rgbt(198, 235, 197, 0));
	else
		return (make_rgbt(161, 195, 152, 0));
}

static int	pal_3(int i)
{
	if (i % 5 == 0)
		return (make_rgbt(229, 61, 0, 0));
	else if (i % 5 == 1)
		return (make_rgbt(255, 233, 0, 0));
	else if (i % 5 == 2)
		return (make_rgbt(252, 255, 247, 0));
	else if (i % 5 == 3)
		return (make_rgbt(33, 160, 160, 0));
	else
		return (make_rgbt(4, 104, 101, 0));
}

int	get_pal(int i, int pal_no)
{
	if (pal_no == 2)
		return (pal_2(i));
	else if (pal_no == 3)
		return (pal_3(i));
	return (pal_1(i));
}
