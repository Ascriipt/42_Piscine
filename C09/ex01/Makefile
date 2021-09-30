# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maparigi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 16:02:47 by maparigi          #+#    #+#              #
#    Updated: 2021/09/29 17:34:58 by maparigi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./srcs/ft_putchar.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c ./srcs/ft_putstr.c ./srcs/ft_swap.c

OBJS	=	${SRCS:.c=.o}

FLAGS	=	-Wall -Wextra -Werror

INCLUDES	=	./includes

.c.o:
		gcc ${FLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
