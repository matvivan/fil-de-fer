/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 10:15:28 by matvivan          #+#    #+#             */
/*   Updated: 2019/12/22 14:52:56 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "miniLibX/mlx.h"

# define W 422
# define H 750

struct			pxls
{
	int			size;
	char		*addr;
	int			byte;
	int			endian;
};

struct			dots
{
	int			max;
	char		***arr;
	int			rows;
	int			cols;
	float		scale;
	void		(*view)();
	int			horz;
	int			vert;
};

struct			ptr
{
	void		*mlx;
	void		*win;
	struct dots	*map_p;
	char		**like;
	char		**book;
	char		**text;
};

void 			fdf(struct dots	map);
int				interior(struct ptr *desk);
void			xpm_init(struct ptr *desk);
void			draw(struct ptr desk, void (*view)(), float scale);
void			projection(struct pxls d, struct dots m, int ppi, int align);
void			parallel(struct pxls d, int x, int y, int k);
void			iso(struct pxls data, int x, int y, int k);
int				button(struct ptr d, int x, int y, int t);
int				key_hook(int key, struct ptr *d);
int				mouse_release(int click, int x, int y, struct ptr *d);
int				mouse_hook(int click, int x, int y, struct ptr *d);

#endif
