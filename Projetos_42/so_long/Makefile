# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 13:45:23 by lucasmar          #+#    #+#              #
#    Updated: 2022/03/16 15:33:29 by lucasmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# libs *********************************************************************** #
PRINTF_PATH =	./libs/ft_printf/
LIBFT_PATH =	./libs/libft/
GNL_PATH =		./libs/gnl/get_next_line.c


PRINTF =		$(PRINTF_PATH)libftprintf.a
LIBFT =			$(LIBFT_PATH)libft.a
HEADERS_PATH=./headers/

# inputs ********************************************************************* #
NAME=so_long

SRC_PATH=./src
OBJ_PATH=./obj

SRC_FILES=validation_input.c\
		  validation_maps.c\
		  error_warning.c\
		  window.c

SRC=$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ=$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

# compilation **************************************************************** #
CC=clang
FLAG=-Wall -Werror -Wextra #-fsanitize=leak
GNL_FLAGS=-D BUFFER_SIZE=10
MLXFLAGS=-I ./libs/mlx -L ./libs/mlx -lmlx -Ilmlx -lXext -lX11 ./libs/mlx/libmlx.a

# clean ********************************************************************** #
RM=-rm -f
RM_DIR=rm -rf

# rules ********************************************************************** #
all:	$(NAME)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAG) -I $(HEADERS_PATH) -c $< -o $@

$(NAME):$(PRINTF) $(LIBFT) $(OBJ)
		@$(CC) $(FLAG) $(GNL_FLAGS) -I $(HEADERS_PATH) -o $@ $(OBJ) \
		$(GNL_PATH) $(LIBFT) $(PRINTF) $(MLXFLAGS)

# message in terminal ************ #
		@echo "\033[1;32m"
		@echo "	so_long created ✓"
		@echo "\033[0m"
		@echo "\033[0;33m	Welcome to So_long game by Lucasmar 42sp \033[0m"
		@echo "\033[0;39m"
		@echo "	run ./so_long in the terminal + map of your choice in ./maps!"
		@echo "	ex: ./so_long ./maps/pdf_map1.ber               "
		@echo "\033[0m"

$(LIBFT):
	@cd $(LIBFT_PATH) && $(MAKE)

$(PRINTF):
	@cd $(PRINTF_PATH) && $(MAKE)

clean:
		@$(RM_DIR) $(OBJ_PATH)
		@echo "\033[0;31m ▥ so_long objects clean ✓ \033[0m"

fclean:		clean
		@$(RM) $(NAME)
		@echo "\033[0;31m ▥ so_long clean ✓ \033[0m"

fcleanlib:
	@cd $(PRINTF_PATH) && $(MAKE) fclean
	@cd $(LIBFT_PATH) && $(MAKE) fclean
	@echo "\033[0;31m ▥ libs clean ✓ \033[0m"

fcleall: fcleanlib fclean
		 @echo "\033[0;31m ▥ libs and so_long clean ✓ \033[0m"

re:			fclean all

reall:		fcleanlib re

.PHONY: all clean fclean fcleanlib fcleanll re reall
