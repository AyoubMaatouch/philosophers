# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 13:11:20 by aymaatou          #+#    #+#              #
#    Updated: 2021/10/11 19:19:35 by aymaatou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = srcs/philo.c srcs/philo_utils.c srcs/ft_atoi.c srcs/ft_isdigit.c srcs/ft_putstr_fd.c srcs/ft_usleep.c srcs/get_time.c
	  
FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) 

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf ./philo.dSYM

re: fclean all