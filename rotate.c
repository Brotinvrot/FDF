/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:38:00 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/29 12:53:10 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float *y, float *z, float angle)
{
	float	previous_y = *y;
	*y = previous_y * cos(angle) + *z * sin(angle);
	*z = -previous_y * sin(angle) + *z * cos(angle);
}

void	rotate_y(float *x, float *z, float angle)
{
	float	previos_x = *x;
	*x = previos_x * cos(angle) + *z * sin(angle);
	*z = -previos_x * sin(angle) + *z * cos(angle);
}

void	rotate_z(float *x, float *y, float angle)
{
	float	previos_x = *x;
	*x = previos_x * cos(angle) - *y * sin(angle);
	*y = previos_x *sin(angle) + *y * cos(angle);
}
