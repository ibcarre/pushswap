# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 23:02:58 by ibaaziz           #+#    #+#              #
#    Updated: 2025/02/24 15:37:33 by ibaaziz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = cost_b2.c\
	ft_bzero.c\
	ft_split.c\
	main.c\
	operations_print.c\
	cost_b.c\
	ft_calloc.c\
	init.c\
	max_min.c\
	sort.c\
	ft_atoi.c\
	ft_isdigit.c\
	lists_op.c\
	operations.c\
	ft_strlen.c\
	operations_print2.c\
	operations2.c\
	change.c\
	sort2.c\

OBJ = $(SRC:.c=.o)

FLAGS += -Werror -Wextra -Wall -I $(INC) -g

$(NAME): $(OBJ)
	cc $(SRC) -o $(NAME) $(FLAGS)

all: $(NAME)

%.o:%.c
	cc ${FLAGS} $< -c

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)


re: fclean all

