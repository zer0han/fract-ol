/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:19:10 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/28 18:18:16 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_mlx_pixel(t_data *data, int x, int y, int c)
{
	char	*dest;

	dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dest = c;
}

int	destroy(t_vars *vars)
{
	get_next_line(-42);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == 'd')
		vars->x0 = vars->x0 + STEP * vars->zoom;
	else if (keycode == 'a')
		vars->x0 = vars->x0 - STEP * vars->zoom;
	else if (keycode == 'w')
		vars->y0 = vars->y0 + STEP * vars->zoom;
	else if (keycode == 's')
		vars->y0 = vars->y0 - STEP * vars->zoom;
	else if (keycode == '=')
		vars->max_iter += 2;
	else if (keycode == '-')
		vars->max_iter -= 2;
	else if (keycode == '1')
		vars->pal_no = 1;
	else if (keycode == '2')
		vars->pal_no = 2;
	else if (keycode == '3')
		vars->pal_no = 3;
	else if (keycode == 'z')
		vars->cy += 0.01;
	else if (keycode == 'x')
		vars->cx -= 0.01;
	else if (keycode == 65307 || keycode == 'q')
		destroy(vars);
	return (0);
}

int	zoom(int button, int x, int y, t_vars *vars)
{
	double	fx;
	double	fy;

	fx = vars->x0 + (x - SIZE_W / 2) * vars->zoom;
	fy = vars->y0 + (y - SIZE_L / 2) * vars->zoom;
	if (button == 4)
		vars->zoom /= ZOOM;
	else if (button == 5)
		vars->zoom *= ZOOM;
	vars->x0 = fx - (x - SIZE_W / 2) * vars->zoom;
	vars->y0 = fy - (y - SIZE_L / 2) * vars->zoom;
	return (0);
}

int	close_window(t_vars *vars)
{
	destroy(vars);
	return (0);
}
