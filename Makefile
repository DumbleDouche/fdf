# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 04:09:13 by rchoquer          #+#    #+#              #
#    Updated: 2017/01/26 06:08:49 by rchoquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
PROJECT			=	FDF

CC				=	gcc
CFLAGS			=	-Werror -Wextra -Wall
CPPFLAGS		=	-Iinclude
OTHERFLAGS		=	-lmlx -framework OpenGL -framework AppKit

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

SRC_NAME		=	drawing.c process.c lists.c input.c get_next_line.c points.c hook.c

OBJ_NAME		=	$(SRC_NAME:.c=.o)
INC_NAME		=	fdf.h get_next_line.h

SRC_PATH		=	src
OBJ_PATH		=	obj
INC_PATH		=	include

SRC				=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ				=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC				=	$(addprefix $(INC_PATH)/,$(INC_NAME))

.PHONY: clean all re fclean

all: $(OBJ_PATH) $(INC) $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_LINK) $(OTHERFLAGS) -g
	@echo $(PROJECT) "  -" "\033[32mBuilt FDF\033[0m"

$(LIB):
	@make -C mlx &> /dev/null
	@echo "MLX   - \033[32mBuilt MLX\033[0m"
	@make -C $(LIB_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $^

$(OBJ_PATH):
	@/bin/mkdir -p $@ > /dev/null

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf $(OBJ_PATH)
	@make -C $(LIB_PATH) clean
	@make -C mlx clean > /dev/null
	@echo $(PROJECT) "  -" "\033[33mCleaned up object files\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) > /dev/null
	@make -C $(LIB_PATH) fclean
	@echo $(PROJECT) "  -" "\033[91mCleaned up compiled files\033[0m"

re: fclean all

norme:
	@echo $(PROJECT) "-" "\033[34mNORME\033[0m"
	@norminette $(SRC)
	@norminette $(INC)
	@make -C libft norme