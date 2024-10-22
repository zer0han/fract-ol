/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:08:24 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/22 22:41:41 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*void	sierpinski_carpet(t_vars *vars, int x, int y, int size)
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
		temp = vars->zx;
		
	}
}*/

void	sierpinski_carpet(t_vars *vars, int x, int y, int size)
{
	int	new_size;

	if (size <= 1)
		return ;
	new_size = size / 3;
	if ((x / new_size) % 3 == 1 && (y / new_size) % 3 == 1)
		put_mlx_pixel(&vars->img, x, y, make_rgbt(11, 5, 0, 0));
	else
	{
		sierpinski_carpet(vars, x, y, new_size);
		sierpinski_carpet(vars, x + new_size, y, new_size);
		sierpinski_carpet(vars, x + 2 * new_size, y, new_size);
		sierpinski_carpet(vars, x, y + new_size, new_size);
		sierpinski_carpet(vars, x + 2 * new_size, y + new_size, new_size);
		sierpinski_carpet(vars, x, y + 2 * new_size, new_size);
		sierpinski_carpet(vars, x + 2 * new_size, y + 2 * new_size, new_size);
	}
}

void	draw_sierpinski(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SIZE_L)
	{
		while (x < SIZE_W)
		{
			sierpinski_carpet(vars, x, y, SIZE_W);
			x++;
		}
		y++;
	}
}
