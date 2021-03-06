# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zweng <zweng@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 13:07:55 by zweng             #+#    #+#              #
#    Updated: 2019/03/02 15:05:15 by zweng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

# ----- part to change -----

NAME 			= fractol

HEADER_PATH 	= includes
SRC_PATH 		= srcs
LIBFT_PATH      = libft
MLX_PATH        = minilibx

LIB 			= libft.a
MLXLIB 			= libmlx.a

HEADER 			= fractol.h
HEADERSP 		= -I$(HEADER_PATH) -I$(MLX_PATH) -I$(LIBFT_PATH)/$(HEADER_PATH)
LIBSP 			= -L$(LIBFT_PATH) -L$(MLX_PATH)
LIBS 			= -lft -lmlx -lm -fsanitize=address
FRAMEWORK 		= -framework OpenGL -framework AppKit

SRC_NAME		= main.c tools.c ft_draw.c ft_event.c ft_fractal.c

OBJ_PATH 		=  obj
OBJ_NAME 		=  $(SRC_NAME:.c=.o)
CFLAGS 			= -Wall -Wextra -Werror

# ----- part automatic -----
SRCS 			:= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS 			:= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# ----- Colors -----
BLACK			:="\033[1;30m"
RED				:="\033[1;31m"
GREEN			:="\033[1;32m"
CYAN			:="\033[1;35m"
PURPLE			:="\033[1;36m"
WHITE			:="\033[1;37m"
EOC				:="\033[0;0m"

# ----- part rules -----

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)/$(LIB) $(MLX_PATH)/$(MLXLIB) 
	@$(CC) $(OBJS) $(HEADERSP) $(LIBSP) $(LIBS) $(FRAMEWORK) -o $@
	@printf $(GREEN)"$(NAME) Finish linking\n"$(EOC)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_PATH)/$(HEADER)| $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(HEADERSP) -o $@ -c $<
	@printf $(GREEN)"compiling %s\n"$(GREEN) $<

$(LIBFT_PATH)/$(LIB):
	@make -C $(LIBFT_PATH)/ fclean && make -C $(LIBFT_PATH)/

$(MLX_PATH)/$(MLXLIB):
	@make -C $(MLX_PATH)/ clean && make -C $(MLX_PATH)/

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null

clean:
	@rm -f $(OBJS)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf $(GREEN)"$(NAME) clean\n"$(EOC)

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT_PATH)/ fclean
	@make -C $(MLX_PATH)/ clean
	@printf $(GREEN)"$(NAME) fclean\n"$(EOC)

re: fclean all

norme:
	@norminette $(SRCS)
	@norminette $(HEADER_PATH)/*.h

.PHONY: clean fclean all re norme
