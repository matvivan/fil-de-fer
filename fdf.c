/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:29:37 by matvivan          #+#    #+#             */
/*   Updated: 2020/01/12 22:29:38 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			circle(struct ptr d, int x, int y, int t)
{
	int i;
	int j;
	int color;

	i = -6;
	color = 0xFFFFFF - 0x777777 * t;
	while (++i < 5 && (j = -6))
		while (++j < 5)
			if (i * i + j * j < 25)
				mlx_pixel_put(d.mlx, d.win, i + x, j + y, color);
}

void			draw(struct ptr desk, void (*f)(), float n)
{
	void		*image;
	struct pxls	data;
	struct dots *map;

	map = desk.map_p;
	if (f)
		map->view = f;
	map->scale *= n;
	image = mlx_new_image(desk.mlx, W, W);
	data.addr = mlx_get_data_addr(image, &data.byte, &data.size, &data.endian);
	if (data.addr && map)
	{
		data.byte /= 8;
		data.size /= data.byte;
		projection(data, *map, 0, 0);
		mlx_put_image_to_window(desk.mlx, desk.win, image, 0, H * 0.14);
	}
	mlx_destroy_image(desk.mlx, image);
	circle(desk, 200, 515, (map->view == &iso));
	circle(desk, 220, 515, (map->view == &parallel));
}

void			fdf(struct dots	map)
{
	struct ptr	desk;

	desk.mlx = mlx_init();
	desk.win = mlx_new_window(desk.mlx, W, H, "Instamap");
	map.vert = 9;
	map.horz = 1;
	map.scale = 100;
	desk.map_p = &map;
	interior(&desk);
	draw(desk, &parallel, 1);
	mlx_key_hook(desk.win, &key_hook, &desk);
	mlx_mouse_hook(desk.win, &mouse_hook, &desk);
	mlx_hook(desk.win, 5, 0, &mouse_release, &desk);
	mlx_hook(desk.win, 17, 0, (int (*)())&exit, NULL);
	mlx_loop(desk.mlx);
}
