# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 04:09:13 by rchoquer          #+#    #+#              #
#    Updated: 2016/12/11 10:45:11 by rchoquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
CPPFLAGS		=	-Iinclude

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

SRC_NAME		=	process.c	drawing.c

OBJ_NAME		=	$(SRC_NAME:.c=.o)
INC_NAME		=	fdf.h

SRC_DIR			=	src
OBJ_DIR			=	obj
INC_DIR			=	include

SRC				=	$(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJ				=	$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))
INC				=	$(addprefix $(INC_DIR)/,$(INC_NAME))
INCS			=	-I$(LIB_PATH)/$(INC_DIR) -I$(INC_DIR)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[32m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

.PHONY: clean all re fclean

all: $(OBJ_DIR) $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(CFLAGS) -o fdf $(OBJ) $(LIB_LINK)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) $(INCS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all
