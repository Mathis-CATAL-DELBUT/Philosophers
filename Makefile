# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 11:15:26 by mcatal-d          #+#    #+#              #
#    Updated: 2023/04/14 03:14:05 by mcatal-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDE = -I./include -I./libft
CC = cc
CFLAGS = -g #-Wall -Wextra -Werror -g
SRC = 	$(addprefix src/, main.c parsing.c init.c routine.c utils.c) \
		$(addprefix src/utils_libft/, ft_atoll.c ft_strlen.c ft_memset.c ft_strncmp.c)
OBJS =	$(patsubst src/%.c, obj/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^ 

clean:
	rm -rf $(OBJS)
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re