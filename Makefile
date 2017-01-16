# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 04:09:13 by rchoquer          #+#    #+#              #
#    Updated: 2017/01/16 22:33:11 by rchoquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
PROJECT			=	FDF

CC				=	gcc
CFLAGS			=	-Werror -Wextra -Wall
CPPFLAGS		=	-Iincludes

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

SRC_NAME		=	drawing.c \
					process.c

OBJ_NAME		=	$(SRC_NAME:.c=.o)
INC_NAME		=	fdf.h

SRC_PATH		=	src
OBJ_PATH		=	obj
INC_PATH		=	includes

SRC				=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ				=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC				=	$(addprefix $(INC_PATH)/,$(INC_NAME))
INCS			=	-I$(LIB_PATH)/$(INC_PATH) -I$(INC_PATH)

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

all: $(OBJ_PATH) $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(CFLAGS) -o fdf $(OBJ) $(LIB_LINK) -lmlx -framework OpenGL -framework AppKit > /dev/null
	@echo $(PROJECT) "  -" "\033[32mBuilt FDF\033[0m"

$(LIB):
	@make -C mlx 1> /dev/null
	@make -C $(LIB_PATH)
	@echo "MLX   - \033[32mBuilt MLX\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $^ > /dev/null

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