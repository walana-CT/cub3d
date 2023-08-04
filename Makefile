# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 10:47:24 by rficht            #+#    #+#              #
#    Updated: 2023/08/04 13:23:32 by mdjemaa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

#-----------------------#
#	Makefile program	#
#-----------------------#

#avoid inheriting variables from the environement
SHELL = /bin/sh

#--- Program name ---#
NAME = cub3d

#--- LIBS ---#
LIBS = -lglfw -L "/Users/mdjemaa/.brew/opt/glfw/lib/" -lft -L libft
LIBMLX = MLX42/build/libmlx42.a
LIBFT = libft/libft.a

#--- Includes ---#
INCLUDES = -I MLX42/include/MLX42 -I includes

# Compil flags
FLAGS = -Wall -Wextra -Werror

# General compilation flags
CFLAG = $(FLAGS)  $(INCLUDES) -fsanitize=address
 
# Linking compilation flags
GFLAG = $(LIBMLX) -g3

OBJ_DIR = objects
SRC_DIR = sources
INCLUDE_DIR = includes

#---------------#
#	Sources		#
#---------------#
FILES += 	cub3d.c\
			parsing_infos_0.c\
			parsing_infos_1.c\
			parsing_map.c\
			parsing.c


SOURCES = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))


# Compiler used for this project
CC = cc

# main rule called by default
all: libs $(NAME)

libs:
	@$(MAKE) -C ./libft

# rule for compile .c -> .o
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@printf '$(GREEN)Compiling: $(RESET)$@\n'
	@$(CC) $(CFLAG) -o $@ -c $<


# create the program
$(NAME): $(OBJ)
	@printf '$(RED)Linking: $(RESET)$@\n'
	@$(CC) $(CFLAG) $(GFLAG) -o $(NAME) $(OBJ) $(LIBS);
	
# remove .o corresponding to sources	
clean:
	@printf ' -- cleaning objects of $(NAME) -- '
	@rm -f $(OBJ)

# remove .o and .a corresponding to sources
fclean: clean
	@printf ' -- cleaning $(NAME) -- '
	@rm -f $(NAME)

# force to recompile everything
re: fclean all

#create the default directories
mkdir: $(SRC_DIR) $(OBJ_DIR) $(INCLUDE_DIR)
$(SRC_DIR):
	mkdir $(SRC_DIR)
$(OBJ_DIR):
	mkdir $(OBJ_DIR)
$(INCLUDE_DIR):
	mkdir $(INCLUDE_DIR)

#help:
#	@echo 'Sources:'
#	@echo $(SOURCES)

#target: dependencies
#		recipies
# $@ target name
# $< first dependencie
# $^ dependencies list
# $? dependencies that ar more recent than target