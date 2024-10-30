/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:47:51 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/29 14:08:57 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z)
{
	if (z == 0)
	{
		int	intensity = fmin(z * 20, 255);
		return (0xFFFF00 - (intensity << 8));
	}
	else
	{
		int	intensity = fmin(-z * 20, 255);
		return (0x00FF00 + (intensity << 16));
	}
}