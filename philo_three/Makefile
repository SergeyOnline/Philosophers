# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 19:27:35 by sbroderi          #+#    #+#              #
#    Updated: 2020/12/03 19:09:47 by sbroderi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

SRC_DIR = ./srcs/

INCLUDES = -I./includes/

LIST = check_args.c \
	   fork_operations.c \
	   ft_atoi.c \
	   ft_isdigit.c \
	   ft_itoa.c \
	   ft_strjoin_char.c \
	   ft_usleep.c \
	   init_philos.c \
	   init_table.c \
	   main.c \
	   print_message.c \
	   ft_strdup.c

SRC = $(addprefix $(SRC_DIR), $(LIST))
OBJ = $(patsubst %.c,%.o,$(SRC))

FLAGS = -Wall -Wextra -Werror -O2

.PHONY: all, clean, fclean, re, norm

all: $(NAME)

$(NAME): $(OBJ)

	gcc $(OBJ) $(INCLUDES) -o $(NAME)

%.o: %.c ./includes/philo_three.h includes/structures.h
	
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

norm:	
	@norminette $(SRC)
	@norminette ./includes/philo_three.h ./includes/structures.h
