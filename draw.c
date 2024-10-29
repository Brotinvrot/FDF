/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:21:07 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/29 10:47:06 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MY_MAX(a, b) (a > b ? a : b)
#define mod(a) ((a < 0) ? -a : a)

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(1) - z;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data -> z_matrix[(int)y][(int)x];
	z1 = data -> z_matrix[(int)y1][(int)x1];

//============ ZOOM ====================
	x *= data -> zoom;
	y *= data -> zoom;
	x1 *= data -> zoom;
	y1 *= data -> zoom;
//=========== COLOR =====================
	data -> color = (z || z1) ? 0xe80c0c : 0xffffff;
//============ 3D ======================
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
//=========== SHIFT ====================
	x += data -> shift_x;
	y += data -> shift_y;
	x1 += data -> shift_x;
	y1 += data -> shift_y;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MY_MAX(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data -> mlx_ptr, data -> win_ptr, x, y, data -> color);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data -> height)
	{
		x = 0;
		while (x < data -> width)
		{
			if (x < data -> width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data -> height -1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}