# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 10:47:24 by rficht            #+#    #+#              #
#    Updated: 2023/07/30 15:04:08 by rficht           ###   ########.fr        #
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
NAME = libgraph.a

#--- LIBS ---#
#--- Includes ---#
INCLUDES = -I ../includes

# Compil flags
FLAGS = -Wall -Wextra -Werror

# General compilation flags
CFLAG = $(FLAGS)  $(INCLUDES) #-fsanitize=address
 
# Linking compilation flags
GFLAG = -g3

OBJ_DIR = objects
SRC_DIR = sources

#---------------#
#	Sources		#
#---------------#
FILES =

SOURCES = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# Compiler used for this project
CC = cc

# main rule called by default
all: $(NAME)

# rule for compile .c -> .o
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@printf '$(GREEN)Compiling: $(RESET)$@\n'
	@$(CC) $(CFLAG) -o $@ -c $<


# create the program
$(NAME): $(OBJ)
	@printf '$(MAGENTA)Creating archive: $(RESET)$@\n'
	@ar rc $@ $^

mkdir: $(SRC_DIR) $(OBJ_DIR)
$(SRC_DIR):
	mkdir $(SRC_DIR)
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

# remove .o corresponding to sources	
clean:
	@printf ' -- cleaning objects libft -- '
	@rm -f $(OBJ)

# remove .o and .a corresponding to sources
fclean: clean
	@printf ' -- deleting libft -- '
	@rm -f $(NAME)

# force to recompile everything
re: fclean all

#help:
#	@echo 'Sources:'
#	@echo $(SOURCES)

#target: dependencies
#		recipies
# $@ target name
# $< first dependencie
# $^ dependencies list
# $? dependencies that ar more recent than target