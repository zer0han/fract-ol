/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:01:16 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/24 20:25:18 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	pal_1(int i)
{
	if (i % 8 == 0)
		return (make_rgbt(150, 40, 53, 23));
	else if (i % 8 == 1)
		return (make_rgbt(90, 120, 67, 57));
	else if (i % 8 == 2)
		return (make_rgbt(130, 244, 193, 220));
	else if (i % 8 == 3)
		return (make_rgbt(143, 143, 20, 130));
	else if (i % 8 == 4)
		return (make_rgbt(200, 117, 40, 150));
	else if (i % 8 == 5)
		return (make_rgbt(242, 141, 60, 42));
	else if (i % 8 == 6)
		return (make_rgbt(208, 105, 240, 98));
	else
		return (make_rgbt(0, 108, 220, 198));
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
