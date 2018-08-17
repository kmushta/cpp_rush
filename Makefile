# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmushta <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 16:56:19 by kmushta           #+#    #+#              #
#    Updated: 2018/03/01 16:56:22 by kmushta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_retro

SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/
LIB_DIR := ./lib/


SRC := main.cpp GameEntity.class.cpp GameState.class.cpp Model.class.cpp \
	Ncurses.class.cpp Bullet.class.cpp Player.class.cpp Enemy.class.cpp \
	Asteroid.class.cpp Boss.class.cpp

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC_FLAGS := -std=c++98 -Wall -Wextra -Werror -O2

LINK_FLAGS := -lncurses

HEADER_FLAGS := -I $(INC_DIR)

CC := clang++

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): $(INC_DIR)*.hpp $(INC_DIR)*.h | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all

vpath %.cpp $(SRC_DIR)

.PHONY: all clean fclean re
