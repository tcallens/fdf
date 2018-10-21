# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcallens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 08:30:21 by tcallens          #+#    #+#              #
#    Updated: 2018/10/21 04:27:03 by tcallens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

INCLUDES = -I ./includes

LIBFT = libft/libft.a

SRCS = ./srcs/main.c\
	   ./srcs/check_valid.c\
	   ./srcs/pars.c\
	   ./srcs/error.c\
	   ./srcs/draw.c\
	   ./srcs/utiles.c\
	   ./srcs/hook.c\

OBJ=$(SRC:.c=.o)

LIB = libft
MLX = miniLibX

FLAG = -lmlx -framework OpenGL -framework AppKit -g3 -Wall -Wextra -Werror

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
RESET = \033[0m

.PHONY : all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ)
	@clear
	@make -C $(LIB)
	@echo "$(GREEN)\t\t\t\t     /|  ---   ---$(RESET)"
	@echo "$(RED)\t\t\t\t      | |   | |   |$(RESET)"
	@echo "$(RED)\t\t\t\t      |  ---   ---\n$(RESET)"
	@echo "\t\t\t---------------------------------------"
	@echo "\t\t\t|$(GREEN)+++++++++$(RESET)                            |"
	@echo "\t\t\t---------------------------------------"
	@echo "$(GREEN)\t\t\t\tlibft has been created.$(RESET)"
	@make -C $(MLX)
	@sleep 1
	@clear
	@echo "$(GREEN)\t\t\t\t     /|  ---   ---$(RESET)"
	@echo "$(RED)\t\t\t\t      | |   | |   |$(RESET)"
	@echo "$(RED)\t\t\t\t      |  ---   ---\n$(RESET)"
	@echo "\t\t\t---------------------------------------"
	@echo "\t\t\t|$(GREEN)++++++++++++++++++$(RESET)                   |"
	@echo "\t\t\t---------------------------------------"
	@echo "$(GREEN)\t\t\t       MiniLibX has been created.$(RESET)"
	@clear
	@echo "$(GREEN)\t\t\t\t     /|  ---   ---$(RESET)"
	@echo "$(GREEN)\t\t\t\t      | |   | |   |$(RESET)"
	@echo "$(RED)\t\t\t\t      |  ---   ---\n$(RESET)"
	@echo "\t\t\t---------------------------------------"
	@echo "\t\t\t|$(GREEN)+++++++++++++++++++++++++++$(RESET)          |"
	@echo "\t\t\t---------------------------------------"
	@echo "$(BLUE)\t\t\tbeginning of the EXECUTABLE's creation.$(RESET)"
	@sleep 1
	@clear
	@echo "$(GREEN)\t\t\t\t     /|  ---   ---$(RESET)"
	@echo "$(GREEN)\t\t\t\t      | |   | |   |$(RESET)"
	@echo "$(GREEN)\t\t\t\t      |  ---   ---\n$(RESET)"
	@echo "\t\t\t---------------------------------------"
	@echo "\t\t\t|$(GREEN)++++++++++++++++SUCCES+++++++++++++++$(RESET)|"
	@echo "\t\t\t---------------------------------------"
	@echo "$(GREEN)\t\t\t--->      fdf has been built.     <---$(RESET)"
	@$(CC) -o3 $(SRCS) $(INCLUDES) ./libft/libft.a -o $(NAME) $(FLAG)

clean:
	@make -C $(LIB) fclean
	@rm -f $(OBJ)
fclean: clean
	@clear
	@$(RM) $(NAME)
	@echo "$(RED)\t\t\t\tft_ls has been removed.$(RESET)"

re: fclean all
