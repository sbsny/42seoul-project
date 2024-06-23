# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 06:21:55 by seonyun           #+#    #+#              #
#    Updated: 2022/11/06 11:26:49 by seonyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS =  src/push_swap.c\
		src/operation.c\
		src/sort_a.c\
		src/sort_b.c\
		src/sort_utils.c\
		src/parsing1.c\
		src/parsing2.c\
		src/ft_split.c
OBJS = $(SRCS:.c=.o)
HEADER = -I./header/

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(HEADER)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re