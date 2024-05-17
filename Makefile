# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 08:14:39 by jsalaber          #+#    #+#              #
#    Updated: 2024/05/17 13:16:20 by jsalaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror -g3

RM		= rm -rf

SRC_DIR = srcs

OBJ_DIR	= obj

SRCS	= $(SRC_DIR)/utils/num_utils.c \
		$(SRC_DIR)/utils/time.c \
		$(SRC_DIR)/utils/error.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/philo.c \


OBJS    = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re