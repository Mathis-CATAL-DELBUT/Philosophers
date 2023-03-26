# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 11:15:26 by mcatal-d          #+#    #+#              #
#    Updated: 2023/03/26 23:12:07 by mcatal-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDE = -I./include -I./libft
CC = cc
CFLAGS = -g #-Wall -Wextra -Werror -g
SRC =  $(addprefix src/, main.c parsing.c)
OBJS = $(patsubst src/%.c, obj/%.o, $(SRC))

all: $(NAME)

libft/libft.a:
	make -C libft

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) libft/libft.a $(OBJS)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^ 

clean:
	make -C libft clean
	rm -rf $(OBJS)
	rm -rf obj

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re