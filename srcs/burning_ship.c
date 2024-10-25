/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:55:33 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/25 19:32:27 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(t_vars *vars, int x, int y)
{
	int		i;
	double	temp;
	double	cx;
	double	cy;

	i = 0;
	vars->zx = 0.0;
	vars->zy = 0.0;
	cx = vars->x0 + (x - SIZE_W / 2) * vars->zoom;
	cy = vars->y0 + (y - SIZE_L / 2) * vars->zoom;
	while (++i < vars->max_iter)
	{
		temp = vars->zx * vars->zx - vars->zy * vars->zy + cx;
		vars->zy = fabs(2.0 * vars->zx * vars-> zy) + cy;
		vars->zx = temp;
		if (vars->zx * vars->zx + vars->zy * vars->zy >= 4.)
			break ;
	}
	if (i == vars->max_iter)
		put_mlx_pixel(&vars->img, x, y, make_rgbt(11, 5, 0, 0));
	else
		put_mlx_pixel(&vars->img, x, y, get_pal(i, vars->pal_no));
}
