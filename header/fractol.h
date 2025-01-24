/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:57 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/24 11:36:01 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stdlib.h>

#define ESC 65307 //"escape"
#define ENTER 65293 // "enter"
#define FOLLOW 102 // "f"
#define COLOR 99 // "c"
#define UP 65362 // "UP"
#define DOWN 65364// "DOWN"
#define PENGUIN 112 // "p"
#define RAND_COLOR 114 // "r"

typedef struct s_win
{ 
    void    *mlx_ptr;
    void    *win_ptr;
}   t_win;

typedef struct s_img
{   
    t_win   *win;
    void    *img_ptr;
    char    *data;
    int     h;
    int     w;
    int     bpp;
    int     endian;
    int     line_len;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom;
	unsigned int	it_max;
} t_img;

void    create_window(t_win *window);
int		exit_window(t_img *image);
int     read_keys(int key_pressed, void *param);
void	mandelbrot(t_img *img);
t_img	new_img(int w, int h, t_win *window);

#endif
