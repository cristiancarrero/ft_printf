# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 18:54:43 by marvin            #+#    #+#              #
#    Updated: 2024/06/01 18:54:43 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
INCLUDE = ft_printf.h

SRC     = ft_printf.c          \
           ft_basics.c         \
           ft_hexadecimals.c    \
           ft_pointers.c       

OBJ     = ${SRC:.c=.o}

CC      = gcc
RM      = rm -f
AR      = ar rc
RN      = ranlib

CFLAGS  = -Wall -Wextra -Werror -I.

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): ${OBJ}
	@echo "Compiling .."
	${AR} ${NAME} ${OBJ}
	${RN} ${NAME}
	@echo "Done !"

clean:
	@echo "Removing .o files..."
	${RM} ${OBJ}
	@echo "Done !"

fclean: clean
	@echo "Removing lib..."
	${RM} $(NAME)
	@echo "Done !"

re: fclean all
