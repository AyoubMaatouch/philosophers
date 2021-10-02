# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 13:11:20 by aymaatou          #+#    #+#              #
#    Updated: 2021/10/01 20:48:15 by aymaatou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c philo_utils.c
#BONUS = pipex_bonus.c exec_children_bonus.c
	  
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME)

$(NAME): $(SRC)
	make -C ./libft
	$(CC) $(FLAGS) -o $(NAME) $(SRC) libft/libft.a

clean:
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME) 

bonus: fclean
	make -C ./libft
	$(CC) -o $(NAME) $(BONUS) libft/libft.a

re: fclean all