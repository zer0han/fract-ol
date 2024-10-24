/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:08:27 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/24 20:43:47 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_vars *vars, int x, int y)
{
	int		i;
	double	temp;

	i = 0;
	vars->zx = vars->x0 + (x - SIZE_W / 2) * vars->zoom;
	vars->zy = vars->y0 + (y - SIZE_L / 2) * vars->zoom;
	while (++i < vars->max_iter)
	{
		temp = vars->zx;
		vars->zx = vars->zx * vars->zx - vars->zy * vars->zy + vars->cx;
		vars->zy = 2 * vars->zy * temp + vars->cy;
		if (vars->zx * vars->zx + vars->zy * vars->zy >= 4.)
			break ;
	}
	if (i == vars->max_iter)
		put_mlx_pixel(&vars->img, x, y, make_rgbt(11, 5, 0, 0));
	else
		put_mlx_pixel(&vars->img, x, y, get_pal(i, vars->pal_no));
}
