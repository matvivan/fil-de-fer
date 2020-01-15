/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:31:47 by matvivan          #+#    #+#             */
/*   Updated: 2019/12/22 19:11:43 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void		parallel(struct pxls d, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < W && y >= 0 && y < W)
	{
		color = 999 - color;
		i = -1;
		while (++i < d.byte)
		{
			d.addr[i + (x * d.size + y) * d.byte] = color % 10 * 255 * 0.111;
			color /= 10;
		}
	}
}

void		iso(struct pxls data, int x, int y, int k)
{
	float	i;
	float	j;

	i = 0.5 * (x + y) * cos(35 * M_PI / 180) - k * sin(35 * M_PI / 180);
	j = 0.5 * (y - x) + 0.5 * data.size;
	parallel(data, i, j, k);
}

int			avg(struct dots map, int i, int j, int sect)
{
	int		x;
	int		y;
	int		diff;
	int		average;

	x = i / sect;
	y = j / sect;
	average = ft_atoi(map.arr[x][y]);
	if (map.arr[x + 1])
	{
		diff = (ft_atoi(map.arr[x][y]) - ft_atoi(map.arr[x + 1][y]));
		average -= diff * (i % sect) / sect;
	}
	if (map.arr[x][y + 1])
	{
		diff = (ft_atoi(map.arr[x][y]) - ft_atoi(map.arr[x][y + 1]));
		average -= diff * (j % sect) / sect;
	}
	return (average);
}

void		projection(struct pxls data, struct dots map, int ppi, int align)
{
	int		i;
	int		j;
	int		sect;

	sect = 0;
	while (sect < 1 + (int)map.scale / 25)
		sect = data.size * ++ppi / (map.rows > map.cols ? map.rows : map.cols);
	align = map.horz + (data.size - (map.cols - 1) * sect / ppi) / 2;
	i = 0;
	while (i <= (map.rows - 1) * sect)
	{
		j = 0;
		while (j <= (map.cols - 1) * sect)
		{
			if (i % sect == 0 || j % sect == 0)
				map.view(data, i * (int)map.scale / ppi / 100 + map.vert, \
									j * (int)map.scale / ppi / 100 + align, \
					avg(map, i, j, sect) * (int)map.scale / 50);
			++j;
		}
		++i;
	}
}
