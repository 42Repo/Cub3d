# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 17:42:16 by asuc              #+#    #+#              #
#    Updated: 2024/07/06 17:16:51 by asuc             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include utils.mk

NAME = cub3D
CFLAGS			=	-Wextra -Wall -Werror
MacroLibX_DIR	=	$(shell pwd)/MacroLibX/
LIBFT_DIR		=	$(shell pwd)/Libft/
LIBFT			=	$(LIBFT_DIR)libft.a
IFLAGS 			=	-I include -I Libft/include -I $(MacroLibX_DIR)includes
COMPIL			=	cc
CC 				=	$(COMPIL) $(CFLAGS) $(IFLAGS) $(FLAGS_OPTI)
MACROLIBX		=	$(MacroLibX_DIR)libmlx.so
CACHE_DIR		=	$(addprefix $(shell pwd)/, .cache)
MAKE			=	make --no-print-directory

SRC = src/main.c \
src/exit.c       \
src/mouse_hook.c \
src/keyboard_hook.c \
src/set_game.c   \
src/set_image.c  \
src/screen_state.c \
src/manage_screen_state.c \
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
src/preload_textures.c \
src/movement/game_controls.c \
src/movement/keyboard_movement.c \
src/movement/mouse_movement.c \
src/movement/movement_utils.c \
src/minimap/rotate_minimap.c \
src/minimap/player_minimap.c \
src/minimap/minimap_utils.c \
src/render.c \
src/resize_textures.c \
src/menu/main/menu.c \
src/menu/main/init_menu.c \
src/menu/main/image_menu.c \
src/floor_ceiling_render/render_data.c \
src/floor_ceiling_render/pixel_render.c \
src/floor_ceiling_render/floor_ceiling_render.c \
src/menu/settings/settings_menu.c \
src/menu/settings/init_settings_menu.c \
src/menu/settings/settings_buttons.c

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

# ERROR JE M"EN FOUT 	= -Wlong-long -std=c2x  -Wwrite-strings -Wbad-function-cast -Wsuggest-attribute=const 

# GCC FLAGS :
# debug: DEBUG_FLAGS := -Warith-conversion -Walloc-zero -Wc11-c2x-compat -Wcoverage-mismatch	-Wdiscarded-qualifiers	  -Wdiscarded-array-qualifiers  -Wduplicated-branches -Wdesignated-init -Wl,--gc-sections -Wl,--as-needed -Wl,--strip-all -Wl,--relax -ffunction-sections -Wl,--gc-sections -Wl,--print-gc-sections -Wanalyzer-double-fclose -Wanalyzer-double-free -Wformat-contains-nul -Wanalyzer-exposure-through-output-file -Wanalyzer-file-leak -Wanalyzer-free-of-non-heap -Whsa -Wif-not-aligned -Wanalyzer-malloc-leak -Wanalyzer-mismatching-deallocation -Wanalyzer-null-argument -Wanalyzer-null-dereference -Wanalyzer-possible-null-argument -Winvalid-memory-model -Wjump-misses-init  -Wmemset-elt-size -Wmaybe-uninitialized -Wanalyzer-possible-null-dereference -Wmissing-parameter-type -Wanalyzer-shift-count-negative -Wnormalized=nfc -Wold-style-declaration -Wnonnull-compare -Wanalyzer-shift-count-overflow -Wpacked-not-aligned -Wpacked-bitfield-compat -Wanalyzer-stale-setjmp-buffer -Wanalyzer-tainted-array-index -Wscalar-storage-order -Wanalyzer-too-complex -Wanalyzer-unsafe-call-within-signal-handler -Wanalyzer-use-after-free -Wstack-usage=8192 -Wstringop-truncation  -Wswitch-outside-range -Wtrampolines -Wswitch-unreachable -float-constants -Wunsuffixed -Wsync-nand -Wanalyzer-use-of-pointer-in-stale-stack-frame  -Wsuggest-final-types -Wsuggest-attribute=cold  -Wsuggest-attribute=malloc  -Wsuggest-final-methods -Wvector-operation-performance -Wformat-overflow=2 -Wformat-truncation=2 -Wmissing-attributes -Wmultistatement-macros -Wcast-align=strict -Wstringop-overflow=4 -Wunused-const-variable=2 -Wtrivial-auto-var-init -Wsync-nand -Wshadow-compatible-local -Wshadow-local -Wattribute-alias=2 -Warray-bounds=2 -Wzero-length-bounds  -Wvla-larger-than=4096 -Wduplicated-cond  -Wduplicated-branches -Wjump-misses-init -Wshadow=local -Wunused-const-variable=1 -Wshift-overflow=2 -Wlogical-op  -Wformat-signedness  -Wsuggest-attribute=format -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure

#CLANG FLAG : 
# debug: DEBUG_FLAGS := -Weverything
# -pedantic-errors -pedantic -Wpedantic

fast : CFLAGS += -Ofast -march=native -mtune=native -flto -ffast-math -funroll-loops -fomit-frame-pointer -finline-functions -fno-plt -fno-semantic-interposition  -falign-functions=32 -falign-loops=32 -fno-math-errno -fno-trapping-math -freciprocal-math -fno-signed-zeros -fno-associative-math
fast : clean all

debug: CFLAGS += -O1 -Wno-padded -Waggregate-return  -Walloca -Warray-parameter -Wattribute-warning  -Wcomment  -Wcpp -Wdeclaration-after-statement  -Wdiv-by-zero -Wduplicate-decl-specifier -Wempty-body -Wendif-labels -Wenum-compare -Wenum-conversion -Wexpansion-to-defined -Wfloat-conversion  -Wformat-extra-args -Wformat-zero-length -Wframe-address -Wframe-larger-than=4096 -Wfree-nonheap-object   -Wignored-attributes  -Wimplicit -Wimplicit-function-declaration -Wimplicit-int -Wincompatible-pointer-types -Winfinite-recursion -Winline -Wint-conversion -Wint-in-bool-context -Wint-to-pointer-cast   -Wlarger-than=4096 -Wmain  -Wmemset-transposed-args -Wmisleading-indentation -Wmissing-braces  -Wmissing-prototypes -Wmultichar -Wnarrowing -Wnonnull  -Wnull-dereference -Wodr  -Woverflow -Woverlength-strings -Woverride-init  -Wparentheses -Wpointer-compare -Wpointer-sign -Wpointer-to-int-cast -Wpragmas -Wpsabi -Wreturn-local-addr  -Wsequence-point -Wshift-negative-value -Wshift-overflow -Wsizeof-array-argument -Wsizeof-pointer-div -Wsizeof-pointer-memaccess   -Wswitch-bool  -Wtautological-compare  -Wtrigraphs -Wtype-limits -Wuninitialized  -Wunused -Wunused-label -Wunused-local-typedefs -Wunused-parameter -Wunused-result -Wunused-value -Wunused-variable -Wvarargs -Wvariadic-macros  -Wvla -Wvolatile-register-var  -Wdangling-else -Wdouble-promotion  -Wimplicit-fallthrough -Winvalid-pch  -Wpacked -Wpointer-arith -Wredundant-decls  -Wsign-conversion  -Wswitch-default -Wswitch-enum   -Wuninitialized  -Wunused-but-set-variable -fstack-protector-strong -D_FORTIFY_SOURCE=2 -pipe -fno-plt -fvisibility=hidden -fstack-clash-protection -fcf-protection -Wsign-conversion -Wconversion   -Wlogical-not-parentheses -Wnull-dereference -Wno-strict-prototypes   -Wswitch-enum  -Wunused-macros -Wdate-time -gdwarf-4 -g3  -Wcast-align -Wcast-qual -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs -Wredundant-decls -Wshadow -Wstrict-aliasing=2 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option -Wdouble-promotion -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wmissing-declarations -Wmissing-field-initializers -Wmissing-noreturn -Wnested-externs -Wold-style-definition -Wpointer-arith -Wstack-protector  -Wunreachable-code -Wunused-but-set-parameter
debug: CFLAGS += $(DEBUG_FLAGS)
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
