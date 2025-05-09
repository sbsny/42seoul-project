all:
		mkdir -p ${HOME}/data ${HOME}/data/mariadb ${HOME}/data/wordpress
		docker-compose -f ./srcs/docker-compose.yml up --build

clean:
		docker-compose -f ./srcs/docker-compose.yml down --volumes

fclean: clean
		docker image prune -af
		sudo rm -rf ${HOME}/data

re:		fclean all

.PHONY:	all clean fclean re
