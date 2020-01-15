/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 10:14:17 by matvivan          #+#    #+#             */
/*   Updated: 2019/12/22 15:07:09 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			profile(void *mlx, void *window, int x, int y)
{
	int		i;
	int		j;
	char	*pixmap;
	int		w;
	int		height;

	pixmap = mlx_xpm_file_to_image(mlx, "xpm/matvivan.xpm", &w, &height);
	mlx_put_image_to_window(mlx, window, pixmap, x + 2, y + 4);
	w /= 2;
	w += 2;
	i = -w;
	while (i < w + 2)
	{
		j = -w;
		while (j < w + 2)
		{
			if ((i * i + j * j) > w * w)
				mlx_pixel_put(mlx, window, x + i + w, y + j + w, 0xB5B5B5);
			if (i * i + j * j >= 490 && i * i + j * j <= 580)
				mlx_pixel_put(mlx, window, x + i + w, y + j + w, 0xFF0000);
			++j;
		}
		++i;
	}
	return (0);
}

int			button(struct ptr d, int x, int y, int t)
{
	int i;
	int j;
	int len;
	int col;

	len = ft_strlen(d.text[t % 10]) * 1.4 * 10 - 1;
	i = -1;
	while (++i < 35 && (j = -1))
		while (++j < len + 1)
		{
			col = 0xFFFFFF;
			if (i % 34 == 0 || j % len == 0)
			{
				col *= (!i | !j) ^ (t / 10);
				mlx_pixel_put(d.mlx, d.win, j + x, i + y, col);
				mlx_pixel_put(d.mlx, d.win, j + x + 1, i + y - 1, col);
			}
			else if ((i + j) % 2 && t / 10)
				mlx_pixel_put(d.mlx, d.win, j + x, i + y, col);
			else
				mlx_pixel_put(d.mlx, d.win, j + x, i + y, 0xB5B5B5);
		}
	mlx_string_put(d.mlx, d.win, x + j / 6.5, y + 5, 0x3F3F3F, d.text[t % 10]);
	return (0);
}

void		header(struct ptr d)
{
	int		i;
	int		w;
	int		h;
	char	*pixmap;

	mlx_string_put(d.mlx, d.win, W / 2 - 15, 8, 0x1F1F1F, "FdF");
	i = 9;
	while (++i < W - 10)
	{
		mlx_pixel_put(d.mlx, d.win, i, H * 0.055, 0x0F0F0F);
		mlx_pixel_put(d.mlx, d.win, i + 1, H * 0.055 + 1, 0xF0F0F0);
	}
	profile(d.mlx, d.win, 15, H * 0.0675);
	mlx_string_put(d.mlx, d.win, 75, H * 0.0825, 0x1F1F1F, "matvivan");
	pixmap = mlx_xpm_file_to_image(d.mlx, "xpm/verif.xpm", &w, &h);
	mlx_put_image_to_window(d.mlx, d.win, pixmap, 160, H * 0.0825);
	button(d, W - 51, 55, 4);
}

void		bottom(struct ptr d)
{
	int		w;
	int		h;
	char	*tmp;

	button(d, 15, H * 0.72, 1);
	button(d, 75, H * 0.72, 2);
	button(d, 176, H * 0.72, 3);
	tmp = mlx_xpm_to_image(d.mlx, d.book, &w, &h);
	mlx_put_image_to_window(d.mlx, d.win, tmp, W - 46, H * 0.72);
	tmp = mlx_xpm_to_image(d.mlx, d.like, &w, &h);
	mlx_put_image_to_window(d.mlx, d.win, tmp, 15, H * 0.787);
	mlx_string_put(d.mlx, d.win, 47, H * 0.78, 0x1F1F1F, d.text[0]);
	mlx_string_put(d.mlx, d.win, 37, H * 0.78, 0x1F1F1F, d.text[5]);
	mlx_string_put(d.mlx, d.win, 15, H * 0.82, 0x1F1F1F, d.text[6]);
	mlx_string_put(d.mlx, d.win, 105, H * 0.82, 0x5F5F5F, d.text[7]);
	mlx_string_put(d.mlx, d.win, 15, H * 0.86, 0x5F5F5F, d.text[8]);
	mlx_string_put(d.mlx, d.win, 15, H * 0.9, 0x5F5F5F, d.text[9]);
	mlx_string_put(d.mlx, d.win, 325, H * 0.9, 0x8F8F8F, d.text[10]);
	mlx_string_put(d.mlx, d.win, 15, H * 0.95, 0x9F9F9F, d.text[11]);
}

int			interior(struct ptr *desk)
{
	int		i;
	int		j;

	i = -1;
	while (++i < H && (j = -1))
		while (++j < W)
			if (!j || i == 527)
				mlx_pixel_put(desk->mlx, desk->win, j, i, 0xFFFFFF);
			else
				mlx_pixel_put(desk->mlx, desk->win, j, i, 0xB5B5B5);
	xpm_init(desk);
	header(*desk);
	bottom(*desk);
	return (0);
}
