/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:01:13 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/22 22:45:56 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	vars_init(t_vars *vars, char *model)
{
	char	*real;
	char	*imgnry;

	vars->x0 = 0.0;
	vars->y0 = 0.0;
	vars->cx = 0.0;
	vars->cy = 0.0;
	vars->zoom = 4.0 / SIZE_W;
	vars->max_iter = 80;
	vars->pal_no = 1;
	vars->img.img = mlx_new_image(vars->mlx, SIZE_W, SIZE_L);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, \
						&vars->img.line_len, &vars->img.enddian);
	vars->model = ft_isfractal(model);
	if (vars->model == 2)
	{
		ft_printf("Input real nbr float: ");
		real = get_next_line(IN);
		ft_printf("Input imgnry nbr float: ");
		imgnry = get_next_line(IN);
		vars->cx = ft_atoi(real);
		vars->cy = ft_atoi(imgnry);
	}
}

int	show_img(t_vars *vars)
{
	int	x;
	int	y;

	mlx_clear_window(vars->mlx, vars->win);
	x = -1;
	while (++x < SIZE_W)
	{
		y = -1;
		while (++y < SIZE_L)
		{
			if (vars->model == 1)
				mandelbrot(vars, x, y);
			else if (vars->model == 2)
				mandel_cube(vars, x, y);
			else if (vars->model == 3)
				mandel__quatro(vars, x, y);
			else if (vars->model == 4)
				julia(vars, x, y);
			else if (vars->model == 5)
				burning_ship(vars, x, y);
			else if (vars->model == 6)
				draw_sierpinski(vars);
		}
	}
	mlx_put_image_to_window(vars-> mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	expose(t_vars *vars)
{
	show_img(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	
}
{
	return (0);
}
