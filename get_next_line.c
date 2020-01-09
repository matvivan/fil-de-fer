/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:05:38 by matvivan          #+#    #+#             */
/*   Updated: 2019/10/25 13:07:45 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "get_next_line.h"

void				replace(char **old, char *new)
{
	if (*old)
		free(*old);
	*old = new;
}

void				get_buffer(int fd, char **ln, char *buff)
{
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		replace(ln, ft_strjoin(*ln, buff));
		if (ft_strchr(buff, '\n'))
			break ;
		ft_strclr(buff);
	}
	free(buff);
}

char				**in_list(t_list *occur, size_t fd, t_list **root)
{
	while (occur)
		if (occur->content_size == fd)
			return (char **)&(occur->content);
		else
			occur = occur->next;
	ft_lstadd(root, ft_lstnew("", 1));
	(*root)->content_size = fd;
	return (char **)&((*root)->content);
}

void				split(char **orig, char **line, char *adr)
{
	if (adr)
		*line = ft_strsub(*orig, 0, adr++ - *orig);
	else if ((adr = ""))
		*line = ft_strdup(*orig);
	replace(orig, ft_strdup(adr));
}

int					get_next_line(const int fd, char **line)
{
	char			**occur;
	static t_list	*gnl;

	if (!read(fd, NULL, 0))
	{
		occur = in_list(gnl, (size_t)fd, &gnl);
		get_buffer(fd, occur, ft_strnew(BUFF_SIZE));
		if (**occur)
		{
			split(occur, line, ft_strchr(*occur, '\n'));
			return (1);
		}
		return (0);
	}
	return (-1);
}
