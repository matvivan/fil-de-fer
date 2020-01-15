#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matvivan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 17:40:21 by matvivan          #+#    #+#              #
#    Updated: 2020/01/14 01:22:38 by matvivan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = get_next_line.c main.c interior.c projection.c fdf.c xpm.c hooks.c

MLX = -LminiLibX/ -lmlx -framework OpenGL -framework AppKit

FT = -Llibft/ -lft

CFLAG = -Wall -Wextra -Werror

all: library $(NAME)

$(NAME): $(SRC)
	gcc $(CFLAG) -c $^
	gcc $(^:.c=.o) -o $@ $(MLX) $(FT) -g

library:
	@make -C libft/
	@make -C miniLibX/

clean:
	@make -C libft/ clean
	@make -C miniLibX/ clean
	rm -rf $(SRC:.c=.o)

fclean: clean
	@make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all