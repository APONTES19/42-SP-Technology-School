# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 13:33:04 by lucasmar          #+#    #+#              #
#    Updated: 2022/04/19 17:41:16 by lucasmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libs *********************************************************************** #

PATH_HEADERS=./includes/
PATH_PRINTF=./libs/ft_printf/
PATH_LIBFT=./libs/libft/

PRINTF=$(PATH_PRINTF)libftprintf.a
LIBFT=$(PATH_LIBFT)libft.a

# inputs ********************************************************************* #

NAME=pipex

PATH_SRC=./src
PATH_OBJ=./obj

SRC_FILES=pipex.c\
		  error.c\
		  check_input.c\
		  pi.c

SRC=$(addprefix $(PATH_SRC)/, $(SRC_FILES))
OBJ=$(SRC:$(PATH_SRC)/%.c=$(PATH_OBJ)/%.o)

# compilation **************************************************************** #

CC=clang
CFLAG=-Wall -Werror -Wextra #$(LEAK)
LEAK=fsanitize=leak

# clean ********************************************************************** #

RM=rm -rf

# rules ********************************************************************** #

all:$(NAME)

clean:
	@$(RM) $(PATH_OBJ)
	@echo "\033[0;31m       ▥ pipex objects clean ✓ \033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31m       ▥ pipex clean ✓ \033[0m"

fcleanlib:
	@cd $(PATH_PRINTF) && $(MAKE) fclean --no-print-directory
	@cd $(PATH_LIBFT) && $(MAKE) fclean --no-print-directory
	@echo "\033[0;31m       ▥ libs clean ✓ \033[0m"

fcleall: fcleanlib fclean
	@echo "\033[0;31m       ▥ libs and piepx clean ✓ \033[0m"

re: fcleall all

# Make_libs ****************************************************************** #

$(LIBFT):
	@cd $(PATH_LIBFT) && $(MAKE) --no-print-directory
$(PRINTF):
	@cd $(PATH_PRINTF) && $(MAKE) --no-print-directory

# Dependencies *************************************************************** #

$(PATH_OBJ)/%.o:	$(PATH_SRC)/%.c
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(CFLAG) -I $(PATH_HEADERS) -c $< -o $@

$(NAME):$(PRINTF) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAG) $(OBJ) -o $@ -I $(PATH_HEADERS) $(LIBFT) $(PRINTF)
#@norminette
	@echo "\033[1;32m\n       Pipex Created ✓ \n\033[0m"

# Prevention *************************************************************** #

.PHONY: all clean fclean fcleanlib fcleall re
