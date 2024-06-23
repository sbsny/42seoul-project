# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 05:10:10 by seonyun           #+#    #+#              #
#    Updated: 2022/11/19 18:25:08 by seonyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
SRCS = philo.c utils.c actions.c thread_op.c
OBJS = $(SRCS:.c=.o)
HEADER = -I -Ipthread

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(HEADER)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -o $@ $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re
