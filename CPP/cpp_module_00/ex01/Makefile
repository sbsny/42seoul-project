# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 21:08:12 by seonyun           #+#    #+#              #
#    Updated: 2023/01/20 00:42:34 by seonyun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PhoneBook
SRCS	=	main.cpp \
			PhoneBook.cpp \
			Contact.cpp
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

re :
			make fclean
			make all

.PHONY:		all clean fclean re
