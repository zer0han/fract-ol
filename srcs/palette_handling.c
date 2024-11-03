/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:01:16 by rdalal            #+#    #+#             */
/*   Updated: 2024/11/03 19:19:25 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	pal_1(int i)
{
	if (i % 8 == 0)
		return (make_rgbt(255, 255, 0, 255));
	else if (i % 8 == 1)
		return (make_rgbt(0, 0, 139, 139));
	else if (i % 8 == 2)
		return (make_rgbt(0, 0, 144, 144));
	else if (i % 8 == 3)
		return (make_rgbt(0, 0, 148, 148));
	else if (i % 8 == 4)
		return (make_rgbt(0, 0, 152, 152));
	else if (i % 8 == 5)
		return (make_rgbt(0, 0, 156, 156));
	else if (i % 8 == 6)
		return (make_rgbt(255, 255, 255, 255));
	else
		return (make_rgbt(0, 0, 160, 160));
}

static int	pal_2(int i)
{
	if (i % 4 == 0)
		return (make_rgbt(0, 212, 120, 100));
	else if (i % 4 == 1)
		return (make_rgbt(154, 173, 147, 200));
	else if (i % 4 == 2)
		return (make_rgbt(232, 156, 227, 190));
	else
		return (make_rgbt(142, 209, 142, 210));
}

static int	pal_3(int i)
{
	if (i % 5 == 0)
		return (make_rgbt(198, 161, 150, 220));
	else if (i % 5 == 1)
		return (make_rgbt(165, 143, 120, 130));
	else if (i % 5 == 2)
		return (make_rgbt(152, 185, 147, 242));
	else if (i % 5 == 3)
		return (make_rgbt(233, 230, 190, 150));
	else
		return (make_rgbt(184, 154, 201, 150));
}

int	get_pal(int i, int pal_no)
{
	if (pal_no == 2)
		return (pal_2(i));
	else if (pal_no == 3)
		return (pal_3(i));
	return (pal_1(i));
}
