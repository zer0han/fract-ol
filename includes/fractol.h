/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:01:17 by rdalal            #+#    #+#             */
/*   Updated: 2024/10/21 20:12:25 by rdalal           ###   ########.fr       */
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
# define FRAC1 "Julia"
# define FRAC2 "Mandelbrot"
# define FRAC3 "Mandelbrot_2"
# define FRAC4 "Mandelbrot_3"
# define FRAC5 "Burning_ship"
# define FRAC6 "Sierpinski_carpet"
# define SIZE_L 960
# define SIZE_W 540
# define STEP 10.0
# define ZOOM 1.2
# define P_NAME "fractol"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		model;
	int		max_iter;
	int		pla_no;
	t_data	img;
	double	x0;
	double	y0;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zoom;
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		enddian;
}	t_data;

/***error handling***/
int		ft_isfractal(char *s);

void	error_mlx(char *model);

void	error_args(void);

/***colors handling***/
int		make_rgbt(int r, int g, int b, int t);

int		get_color(int rgbt, char i);

int		add_shade(double f, int color);

int		get_opp(int color);

/***draw mandelbrot***/

/***draw Julia***/

/***draw sierpinsky carpet***/

#endif
