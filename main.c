/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:16:58 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/29 16:46:02 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(fdf *data)// что бы крестик в окне работал, так же заработало и сворачивание
{
	(void)data;
	exit(0);
	return (0);
}

int	key_press(int key, fdf *data)
{
	if (key == 65362)
		data -> key_up = 1;
	if (key == 65364)
		data -> key_down = 1;
	if (key == 65361)
		data -> key_left = 1;
	if (key == 65363)
		data -> key_right = 1;
	if (key == 65451) // '+'
		data -> key_zoom_in = 1;
	if (key == 65453) // '-'
		data -> key_zoom_out = 1;
	if (key == 'q')
		data -> key_rotate_x_pos = 1;
	if (key == 'a')
		data -> key_rotate_x_neg = 1;
	if (key == 'w')
		data -> key_rotate_y_pos = 1;
	if (key == 's')
		data -> key_rotate_y_neg = 1;
	if (key == 'e')
		data -> key_rotate_z_pos = 1;
	if (key == 'd')
		data -> key_rotate_z_neg = 1;
	return (0);
}

int	key_release(int key, fdf *data)
{
	if (key == 65362)
		data -> key_up = 0;
	if (key == 65307)
		exit (0);
	if (key == 65364)
		data -> key_down = 0;
	if (key == 65361)
		data -> key_left = 0;
	if (key == 65363)
		data -> key_right = 0;
	if (key == 65451) // '+'
		data -> key_zoom_in = 0;
	if (key == 65453) // '-'
		data -> key_zoom_out = 0;
	if (key == 'q')
		data -> key_rotate_x_pos = 0;
	if (key == 'a')
		data -> key_rotate_x_neg = 0;
	if (key == 'w')
		data -> key_rotate_y_pos = 0;
	if (key == 's')
		data -> key_rotate_y_neg = 0;
	if (key == 'e')
		data -> key_rotate_z_pos = 0;
	if (key == 'd')
		data -> key_rotate_z_neg = 0;
	return (0);
}

int	loop_hook(fdf *data)
{
	int	redraw = 0;
	if (data -> key_up)
	{
		data -> shift_y -= 1;
		redraw = 1;
	}
	if (data -> key_down)
	{
		data -> shift_y += 1;
		redraw = 1;
	}
	if (data -> key_left)
	{
		data -> shift_x -= 1;
		redraw = 1;
	}
	if (data -> key_right)
	{
		data -> shift_x += 1;
		redraw = 1;
	}
	if (data -> key_zoom_in)
	{
		data -> zoom += 1;
		redraw = 1;
	}
	if (data -> key_zoom_out && data -> zoom > 1)
	{
		data -> zoom -= 1;
		redraw = 1;
	}
	if (data -> key_rotate_x_pos)
	{
		data -> angle_x += 0.01;
		redraw = 1;
	}
	if (data -> key_rotate_x_neg)
	{
		data -> angle_x -= 0.01;
		redraw = 1;
	}
	if (data -> key_rotate_y_pos)
	{
		data -> angle_y += 0.01;
		redraw = 1;
	}
	if (data -> key_rotate_y_neg)
	{
		data -> angle_y -= 0.01;
		redraw = 1;
	}
	if (data -> key_rotate_z_pos)
	{
		data -> angle_z += 0.01;
		redraw = 1;
	}
	if (data -> key_rotate_z_neg)
	{
		data -> angle_z -= 0.01;
		redraw = 1;
	}
	if (redraw)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	return (0);
}

/*int	deal_key(int key, fdf *data)// принимаем коды с кнопок что бы изменять изображение
{
	printf("%d\n", key);
	(void)data;
	if (key == 65362)
		data -> shift_y -= 1;
	if (key == 65364)
		data -> shift_y += 1;
	if (key == 65361)
		data -> shift_x -= 1;
	if (key == 65363)
		data -> shift_x += 1;
	if (key == 'q') // Поворот вокруг оси X +
		data->angle_x += 0.05;
	if (key == 'a') // Поворот вокруг оси X -
		data->angle_x -= 0.05;
	if (key == 'w') // Поворот вокруг оси Y +
		data->angle_y += 0.05;
	if (key == 's') // Поворот вокруг оси Y -
		data->angle_y -= 0.05;
	if (key == 'e') // Поворот вокруг оси Z +
		data->angle_z += 0.05;
	if (key == 'd') // Поворот вокруг оси Z -
		data->angle_z -= 0.05;
	if (key == 65453 && data -> zoom > 1) // уменьшение зума -
		data -> zoom -= 1;
	if (key == 65451) // увеличение зума +
		data -> zoom += 1;
	if (key == 65307)
		exit (0);
	mlx_clear_window(data -> mlx_ptr, data -> win_ptr);
	draw(data);
	return (0);
}*/

int	main(int argc, char **argv)
{
	fdf 	*data;
	(void)argc;

	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data -> mlx_ptr = mlx_init();
	data -> win_ptr = mlx_new_window(data -> mlx_ptr, 1000, 1000, "FDF");
	data -> zoom = 20;

	data -> shift_x = (1250 - (data -> width * data -> zoom)) / 2;
	data -> shift_y = (900 - (data -> height * data -> zoom)) / 2;

	draw(data);
	mlx_hook(data->win_ptr, 2, 1L<<0, key_press, data);
	mlx_hook(data->win_ptr, 3, 1L<<1, key_release, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	//mlx_key_hook(data -> win_ptr, deal_key, data);
	//mlx_hook(data->win_ptr, 17, 0, close_window, &data);
	mlx_loop(data -> mlx_ptr);
}
