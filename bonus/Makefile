# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 17:42:16 by asuc              #+#    #+#              #
#    Updated: 2024/06/18 16:17:46 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include utils.mk

NAME = cub3D
CFLAGS		=	-Wall -Werror -Wextra
MacroLibX_DIR	=	$(shell pwd)/MacroLibX/
LIBFT_DIR	=	$(shell pwd)/Libft/
LIBFT		=	$(LIBFT_DIR)libft.a
# FLAGS_OPTI = -Ofast  -march=native -flto -ffast-math -funroll-loops -fomit-frame-pointer -finline-functions  -pipe -fno-plt -fno-stack-protector -fno-stack-check -fno-strict-aliasing -fno-builtin -fno-common  -fno-jump-tables -fno-semantic-interposition -fno-zero-initialized-in-bss
IFLAGS = -I include -I Libft/include -I $(MacroLibX_DIR)includes
CC = clang $(CFLAGS) $(IFLAGS) $(FLAGS_OPTI)
MACROLIBX		=	$(MacroLibX_DIR)libmlx.so
CACHE_DIR	=	$(addprefix $(shell pwd)/, .cache)
MAKE		=	make --no-print-directory

SRC = src/main.c \
src/exit.c       \
src/hook.c       \
src/set_game.c   \
src/set_image.c  \
src/parsing/parsing.c \
src/parsing/parsing_utils.c \
src/parsing/parse_texture.c \
src/parsing/parse_map.c \
src/parsing/check_map.c \
src/parsing/check_params.c \
src/raycasting/dda.c \
src/raycasting/raycasting_utils.c \
src/raycasting/raycast.c \
src/utils.c \
src/mlx_addon/mlx_line.c \
src/mlx_addon/mlx_rectangle.c \
src/preload_textures.c \
src/movement/game_controls.c \
src/movement/keyboard_movement.c \
src/movement/mouse_movement.c \
src/movement/movement_utils.c \
src/render.c \
src/resize_textures.c

OBJ_DIR = $(CACHE_DIR)/obj
DEP_DIR = $(CACHE_DIR)/dep

DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DEP = $(addprefix $(DEP_DIR)/,$(SRC:.c=.d))

_CURR = 0
_TOTAL = $(words $(OBJ))
_TOTAL_LEN = $(shell echo $(_TOTAL) | wc -c)
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@if [ $(_CURR) -eq 1 ]; then \
		printf "$(Bblue)Compilation object files for $(NAME)$(RESET)\n"; \
	fi
	$(eval _CURR=$(shell echo $$(($(_CURR)+1))))
	$(eval _PERCENTAGE=$(shell echo $$(($(_CURR)*100/$(_TOTAL)))))
	@printf "\033[2K$(Green)[$(shell printf "% 3s" "$(_PERCENTAGE)")%%] $(shell printf "%*d/%d" $(_TOTAL_LEN) $(_CURR) $(_TOTAL)) Compiling $<\r"
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEP_DIR)/$*)
	@$(CC) $(DEP_FLAGS) -o $@ -c $<
	@mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@

all : $(NAME)

debug: CFLAGS += -gdwarf-4 -g
debug: clean all

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)

 $(LIBFT):
	@printf "$(Bblue)Compilation object files for libft.a$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) -j

$(MACROLIBX):
	@printf "$(Bblue)Compilation object files for libmlx.so$(RESET)\n"
	@$(MAKE) -C $(MacroLibX_DIR) -j

$(NAME) : $(LIBFT) $(MACROLIBX) $(OBJ)
	@printf "$(Green)\033[2K[100%%] Linking $(NAME)\n"
	@$(CC) -o $(NAME) $(OBJ) -L Libft/ -lft $(MacroLibX_DIR)libmlx.so -lSDL2 -lm
	@printf "$(BGreen)Compilation Final $(NAME)$(RESET)\n"

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MacroLibX_DIR) clean
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@printf "$(BRed)Erase all obj and deb files$(RESET)\n"

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MacroLibX_DIR) fclean
	@rm -rf $(NAME) $(LIBFT) $(CACHE_DIR)
	@printf "$(BRed)Erase $(NAME), libft.a$(RESET)\n\n"

re : fclean all

-include $(DEP)

.PHONY: all fclean clean re
