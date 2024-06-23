# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 04:57:55 by seonyun           #+#    #+#              #
#    Updated: 2023/02/04 16:21:49 by seonyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	file
SRCS	=	main.cpp \
			Zombie.cpp \
			zombieHorde.cpp
OBJS	=	$(SRCS:.cpp=.o)
CXX		=	c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

.cpp.o:
			${CXX} ${CXXFLAGS} -c $< -o ${<:.cpp=.o}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:
			make fclean
			make all

.PHONY:		all clean fclean re
