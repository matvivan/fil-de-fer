/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 23:32:41 by matvivan          #+#    #+#             */
/*   Updated: 2020/01/13 23:32:42 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void				press(struct ptr d, char **icon, int x, int y)
{
	int				w;
	int				h;
	char			*tmp;

	tmp = icon[1];
	icon[1] = icon[2];
	icon[2] = tmp;
	tmp = mlx_xpm_to_image(d.mlx, icon, &w, &h);
	mlx_put_image_to_window(d.mlx, d.win, tmp, x, y);
}

int					key_hook(int key, struct ptr *d)
{
	if (key == 53)
	{
		system("leaks fdf | grep Leak");
		exit(0);
	}
	if (key == 124)
		draw(*d, &iso, 1);
	if (key == 123)
		draw(*d, &parallel, 1);
	if (key == 0 && (d->map_p->horz += 20))
		draw(*d, NULL, 1);
	if (key == 1 && (d->map_p->vert -= 20))
		draw(*d, NULL, 1);
	if (key == 2 && (d->map_p->horz -= 20))
		draw(*d, NULL, 1);
	if (key == 13 && (d->map_p->vert += 20))
		draw(*d, NULL, 1);
	return (0);
}

int					mouse_release(int c, int x, int y, struct ptr *d)
{
	if ((x >= 75 && x <= 173 && y >= H * 0.72 && y <= H * 0.72 + 35) || c)
		button(*d, 75, H * 0.72, 2 + 10 * !c);
	if ((x >= 176 && x <= 246 && y >= H * 0.72 && y <= H * 0.72 + 35) || c)
		button(*d, 176, H * 0.72, 3 + 10 * !c);
	if ((x >= W - 51 && x <= W - 9 && y >= 55 && y <= 90) || c)
	{
		button(*d, W - 51, 55, 4 + 10 * !c);
		if (!c)
		{
			mlx_string_put(d->mlx, d->win, 140, 240, 0xFFFFFF, d->text[12]);
			mlx_string_put(d->mlx, d->win, 140, 270, 0xFFFFFF, d->text[13]);
			mlx_string_put(d->mlx, d->win, 140, 300, 0xFFFFFF, d->text[14]);
			mlx_string_put(d->mlx, d->win, 140, 330, 0xFFFFFF, d->text[15]);
		}
	}
	if (c == 2)
	{
		d->map_p->horz = 1;
		d->map_p->vert = 9;
		d->map_p->scale = 100;
		draw(*d, NULL, 1);
	}
	return (0);
}

int					mouse_hook(int c, int x, int y, struct ptr *d)
{
	if (c == 1)
		mouse_release(0, x, y, d);
	if (c == 1 && x > 15 && x < 70 && y > H * 0.72 && y < H * 0.72 + 35)
	{
		button(*d, 15, H * 0.72, 1 + **(d->text) % 2 * 10);
		press(*d, d->like, 15, H * 0.787);
		mlx_string_put(d->mlx, d->win, 46, H * 0.78, 0xB5B5B5, *(d->text));
		mlx_string_put(d->mlx, d->win, 48, H * 0.78, 0xB5B5B5, *(d->text));
		*(d->text) = (**(d->text) == '1' ? "2" : "1");
		mlx_string_put(d->mlx, d->win, 47, H * 0.78, 0x1F1F1F, *(d->text));
	}
	if (c == 1 && x > W - 46 && x < W - 9 && y > H * 0.72 && y < H * 0.72 + 35)
		press(*d, d->book, W - 46, H * 0.72);
	if (c == 4)
		if ((d->map_p->horz += x / 20 - 5) && (d->map_p->vert += y / 25 - 5))
			draw(*d, NULL, 0.97);
	if (c == 5)
		if ((d->map_p->horz -= x / 20 - 5) && (d->map_p->vert -= y / 25 - 5))
			draw(*d, NULL, 1.03);
	return (0);
}
