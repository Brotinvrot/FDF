/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:21:07 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/29 13:34:33 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MY_MAX(a, b) (a > b ? a : b)
#define mod(a) ((a < 0) ? -a : a)

void	isometric(float *x, float *y, int z)
{
	float previous_x = *x;
	float previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	float	z;
	float	z1;

	z = (float)data -> z_matrix[(int)y][(int)x];
	z1 = (float)data -> z_matrix[(int)y1][(int)x1];

//============ ZOOM ====================
	x *= data -> zoom;
	y *= data -> zoom;
	x1 *= data -> zoom;
	y1 *= data -> zoom;

//============ ROTATION =================
	rotate_x(&y, &z, data -> angle_x);
	rotate_y(&x, &z, data -> angle_y);
	rotate_z(&x, &y, data -> angle_z);

	rotate_x(&y1, &z1, data -> angle_x);
	rotate_y(&x1, &z1, data -> angle_y);
	rotate_z(&x1, &y1, data -> angle_z);

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