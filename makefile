# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 13:58:33 by abellakr          #+#    #+#              #
#    Updated: 2022/05/30 20:05:23 by abellakr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

NAME = minishell
CC = cc
CFlAGS = -Wall -Wextra -Werror
READ_FLAGS    =  -lreadline  -I .brew/opt/readline/include

SRC = minishell.c ./lexer/lexer.c ./lexer/lexer_utils.c
OBJ = $(SRC:.c=.o)

%.o:%.c $(SRC)
	@$(CC) $(CFlAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@echo  $(BPurple)" done ! "$(Color_Off)
	@make -C ./libft
	@$(CC) $(CFlAGS) $(READ_FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)
	@make clean
clean : 
	@make clean -C ./libft
	@rm -f $(OBJ)
fclean : clean
	@make fclean -C ./libft
	@rm -f $(NAME)
re : fclean all
.PHONY : clean fclean bonus re