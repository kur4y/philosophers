# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanota <tanota@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 18:36:00 by tanota            #+#    #+#              #
#    Updated: 2023/10/13 20:29:55 by tanota           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=			cc

CFLAGS			=			-Wall -Wextra -Werror -g

CFLAGS_OBJ		=			-Wall -Wextra -Werror -c -g

RM				=			rm -f

C_FILES			=			error.c			\
							utils.c			\
							utils2.c		\
							free.c 			\
							philo.c 		\
							philo_utils.c 	\
							philo_utils2.c 	\
							eat.c 			\
							ft_itoa.c 		\
							dead.c 			\
							think.c 		\
							sleep.c 		\
							main.c

SRC = $(addprefix src/, $(C_FILES))

OBJ = $(SRC:.c=.o)

INC = -I includes/

LIB = -L. -lft

NAME = philo

all : $(NAME)

libft.a :
			make bonus -C libft

%.o : %.c
			$(CC) $(CFLAGS_OBJ) $< -o $@ $(INC)

$(NAME) : $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
		$(RM) src/*.o

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all fclean clean re