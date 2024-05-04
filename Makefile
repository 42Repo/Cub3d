# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 16:23:45 by bgoron            #+#    #+#              #
#    Updated: 2024/05/04 23:42:50 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAG = -Wall -Wextra -Werror -g -O3
IFLAGS = -I include -I Libft/include -I MacroLibX/includes
CC = cc $(FLAG) $(IFLAGS)

SRC = src/main.c \
src/exit.c       \
src/hook.c       \
src/parse.c      \
src/set_game.c   \
src/set_image.c  \

OBJ_DIR := .obj
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

$(NAME) : $(OBJ)
	@make -C Libft/ -j
	@make -C MacroLibX/ -j
	@$(CC) -o $(NAME) $(OBJ) -L Libft/ -lft MacroLibX/libmlx.so -lSDL2 -lm

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -o $@ -c $^

clean :
	@rm -rf $(OBJ)
	@make -C Libft/ clean

dclean : clean
	@rm -rf $(OBJ_DIR)

fclean : dclean
	@rm -rf $(NAME)

re : fclean all

all: $(NAME)

.PHONY: all clean fclean re