# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 17:03:46 by ralopez-          #+#    #+#              #
#    Updated: 2023/01/14 17:03:48 by ralopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

ifdef TERM
RED			:=	"\033[1;31m"
GREEN		:=	"\033[0;32m"
BGREEN		:=	"\033[1;32m"
BLUE		:=	"\033[0;34m"
YELLOW		:=	"\033[0;33m"
PURPLE		:=	"\033[0;35m"
CYAN		:=	"\033[0;36m"
GREY		:=	"\033[0;37m"
# When printed reset the color
COLRESET	:=	"\033[0m"
endif

SRC = ft_strlen.c ft_atoi.c ft_bzero.c  ft_calloc.c \
	ft_strdup.c ft_itoa.c ft_substr.c ft_strjoin.c ft_split.c  \
	ft_aux_disc.c ft_show_pointer.c ft_strcmp.c ft_printf.c  \
	ft_split_clear.c ft_strchr.c get_next_line.c\
	 ft_errors.c ft_window.c ft_files.c ft_store_map.c ft_validate_map.c \
	 ft_degraded.c ft_bresenham.c ft_colors.c ft_hooks.c  ft_draw.c fdf.c 

OBJ = $(SRC:.c=.o)


%.o: %.c
	@echo $(GREEN) Compiling file $< $(COLRESET)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo $(BLUE) Done!!! $(COLRESET)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

all : $(NAME)

re : fclean all

clean :
	@echo $(RED) clean $(COLRESET)
	@$(RM) $(OBJ)

fclean : clean
	@echo $(RED) fclean $(COLRESET)
	@$(RM) $(NAME)

.PHONY: all clean fclean re 
