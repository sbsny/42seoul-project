# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 00:52:52 by seonyun           #+#    #+#              #
#    Updated: 2023/01/20 01:34:28 by seonyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Account
SRCS	=	tests.cpp \
			Account.cpp
OBJS	=	$(SRCS:.cpp=.o)
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g
RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.cpp.o:
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re :
			make fclean
			make all

.PHONY:		all clean fclean re
