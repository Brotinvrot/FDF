/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:20:38 by drabadan          #+#    #+#             */
/*   Updated: 2024/10/29 13:08:44 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 10

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "minilibx-linux/mlx.h"
#include "fcntl.h"
#include <math.h>

typedef struct	s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}	t_arr;

typedef struct
{
	int	width;//ширина  (x)
	int	height;//высота (y)
	int	**z_matrix;//	(z)
	int	zoom;
	int	color;
	int	shift_x;
	int	shift_y;

	float	angle_x;
	float	angle_y;
	float	angle_z;

	void	*mlx_ptr;
	void	*win_ptr;
}	fdf;

void	bresenham(float x, float y, float x1, float y1, fdf *data);
void 	read_file(char *file_name, fdf *data);
int		ft_atoi(const char *s);
int		get_next_line(const int fd, char **line);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlen(char const *s);
char	*ft_strcat(char *restrict str1, const char *restrict str2);
void	ft_strclr(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_strdel(char **as);
char	**ft_strsplit(char const *str, char c);
int		ft_wdcounter(char const *str, char c);
void	ft_memdel(void **ap);
int		ft_atoi(const char *s);
void	draw(fdf *data);

//========= ROTATE ============
void	rotate_x(float *y, float *z, float angle);
void	rotate_y(float *x, float *z, float angle);
void	rotate_z(float *x, float *y, float angle);

#endif
