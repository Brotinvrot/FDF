/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:16:58 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/29 11:02:11 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(fdf *data)
{
	(void)data;
	exit(0);
	return (0);
}

int	deal_key(int key, fdf *data)// принимаем коды с кнопок что бы изменять изображение
{
	printf("%d\n", key);
	(void)data;
	if (key == 65362)
		data -> shift_y -= 20;
	if (key == 65364)
		data -> shift_y += 20;
	if (key == 65361)
		data -> shift_x -= 20;
	if (key == 65363)
		data -> shift_x += 20;
	if (key == 65307)
		exit (0);
	mlx_clear_window(data -> mlx_ptr, data -> win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	fdf 	*data;
	(void)argc;

	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data -> mlx_ptr = mlx_init();
	data -> win_ptr = mlx_new_window(data -> mlx_ptr, 1000, 1000, "FDF");
	data -> zoom = 20;

	draw(data);
	mlx_key_hook(data -> win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, &data);
	mlx_loop(data -> mlx_ptr);
}