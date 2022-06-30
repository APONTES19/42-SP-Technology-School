# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 13:45:23 by lucasmar          #+#    #+#              #
#    Updated: 2022/06/30 15:54:02 by lucasmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# libs *********************************************************************** #
PRINTF_PATH =	./libs/ft_printf/
LIBFT_PATH =	./libs/libft/

PRINTF =		$(PRINTF_PATH)libftprintf.a
LIBFT =			$(LIBFT_PATH)libft.a
HEADERS_PATH=	./includes/

# inputs ********************************************************************* #
NAME=push_swap

SRC_PATH=./src
OBJ_PATH=./obj

SRC_FILES=push_swap.c\
		  ft_long_atoi.c

SRC=$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ=$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

# compilation **************************************************************** #
CC=cc
FLAG=-Wall -Werror -Wextra #-fsanitize=leak

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
		$(LIBFT) $(PRINTF)
##norminette

# message in terminal ************ #
		@echo "\033[1;32m"
		@echo "	Push_swap created ✓"
		@echo "\033[0m"
		@echo "\033[0;33m	Welcome to Push_swap by Lucasmar 42sp \033[0m"
		@echo "\033[0;39m"
		@echo "	run ./push_swap in the terminal + stack of your choice !"
		@echo "	ex: ./push_swap 2 9 8 5 1 4 2 3 6 0"
		@echo "\033[0m"

$(LIBFT):
	@cd $(LIBFT_PATH) && $(MAKE)

$(PRINTF):
	@cd $(PRINTF_PATH) && $(MAKE)

clean:
		@$(RM_DIR) $(OBJ_PATH)
		@echo "\033[0;31m ▥ Push_swap objects clean ✓ \033[0m"

fclean:		clean
		@$(RM) $(NAME)
		@echo "\033[0;31m ▥ Push_swap clean ✓ \033[0m"

fcleanlib:
	@cd $(PRINTF_PATH) && $(MAKE) fclean
	@cd $(LIBFT_PATH) && $(MAKE) fclean
	@echo "\033[0;31m ▥ libs clean ✓ \033[0m"

fcleall: fcleanlib fclean
		 @echo "\033[0;31m ▥ libs and Push_swap clean ✓ \033[0m"

re:			fclean all

reall:		fcleanlib re

.PHONY: all clean fclean fcleanlib fcleanll re reall
