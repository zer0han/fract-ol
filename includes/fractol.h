/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:17 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/22 22:42:36 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# define IN STDIN_FILENO
# define OUT STDOUT_FILENO
# define ERR STDERR_FILENO
# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define MOVE_MOUSE 6
# define CLOSE 17
# define F1 "julia"
# define F2 "mandelbrot"
# define F3 "mandel_cube"
# define F4 "mandel_quatro"
# define F5 "burning_ship"
# define F6 "sierpinski_carpet"
# define SIZE_L 960
# define SIZE_W 540
# define STEP 10.0
# define ZOOM 1.2
# define P_NAME "fractol"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		enddian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		model;
	int		max_iter;
	int		pal_no;
	t_data	img;
	double	x0;
	double	y0;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zoom;
}	t_vars;

/***error handling***/
int		ft_isfractal(char *s);

void	error_mlx(char *model);

void	error_args(void);

/***colors handling***/
int		make_rgbt(int r, int g, int b, int t);

int		get_color(int rgbt, char i);

int		add_shade(double f, int color);

int		get_opp(int color);

/***mandelbrot***/
void	mandelbrot(t_vars *vars, int x, int y);

void	mandel_cube(t_vars *vars, int x, int y);

void	mandel_quatro(t_vars *vars, int x, int y);

/***julia***/
void	julia(t_vars *vars, int x, int y);

/***burning ship***/
void	burning_ship(t_vars *vars, int x, int y);
/***sierpinsky carpet***/
void	sierpinski_carpet(t_vars *vars, int x, int y, int size);

void	draw_sierpinski(t_vars *vars);

/***mlx utils***/
void	put_mlx_pixel(t_data *data, int x, int y, int c);

int		destroy(t_vars *vars);

int		key_handler(int keycode, t_vars *vars);

int		zoom(t_vars *vars, int button, int x, int y);

int		close_window(t_vars *vars);

/***palette_handling***/
int		get_pal(int i, int pal_no);

#endif
