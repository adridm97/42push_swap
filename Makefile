# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 20:42:13 by aduenas-          #+#    #+#              #
#    Updated: 2023/10/15 20:33:40 by aduenas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = main.c utils.c check_args.c list_instructions.c swap.c push.c rotate.c big.c big_utils.c \
	  get_utils.c r_rotate.c find_utils.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ	=	$(SRC:.c=.o)

all : ${NAME}

${NAME}: ${OBJ}
		make  -C libft/
		${CC} ${CFLAGS} -o ${NAME} ${SRC} libft/libft.a

clean:
		${MAKE} -C libft/ clean
		rm -f ${OBJ}

fclean: clean
		rm -f  ${NAME}
		${MAKE} -C libft/ fclean
re: fclean all

.PHONY: all clean fclean re
