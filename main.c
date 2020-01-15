/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 12:15:13 by matvivan          #+#    #+#             */
/*   Updated: 2020/01/03 12:15:14 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			free_map(char ***arr)
{
	int			i;
	int			j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			free(arr[i][j++]);
		free(arr[i++]);
	}
	free(arr);
}

int				valid_map(struct dots *map)
{
	int			i;
	int			j;

	i = 0;
	map->max = 1;
	map->cols = -1;
	while (map->arr[i])
	{
		j = 0;
		while (map->arr[i][j] && (j < map->cols || map->cols < 0))
		{
			if (ft_atoi(map->arr[i][j]) > map->max)
				map->max = ft_atoi(map->arr[i][j]);
			++j;
		}
		map->cols = j;
		++i;
	}
	return (map->cols);
}

int				input(int fd, char ****arr, int *rows)
{
	int			i;
	char		*line;
	char		***old;

	*rows = 0;
	while (get_next_line(fd, &line) > 0)
	{
		old = (*arr);
		(*arr) = (char ***)malloc(sizeof(char **) * (*rows + 2));
		if (!*arr)
			return (0);
		if (old)
		{
			i = -1;
			while (++i < *rows)
				(*arr)[i] = old[i];
			free(old);
		}
		(*arr)[*rows] = ft_strsplit(line, ' ');
		free(line);
		(*arr)[*rows + 1] = NULL;
		if (!(*arr)[(*rows)++])
			return (0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	int			fd;
	struct dots	map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!read(fd, NULL, 0))
		{
			map.arr = NULL;
			if (input(fd, &map.arr, &map.rows) && valid_map(&map))
				fdf(map);
			free_map(map.arr);
			close(fd);
		}
		else
			ft_putendl("\t[error] Wrong file.");
	}
	else
		ft_putendl("\tUsage : ./fdf <filename>");
	return (0);
}
