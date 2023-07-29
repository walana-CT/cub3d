# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 10:47:24 by rficht            #+#    #+#              #
#    Updated: 2023/07/27 17:45:18 by rficht           ###   ########.fr        #
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
NAME = libft.a

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
FILES =	ft_abs_int.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_get_next_line.c\
		ft_get_next_line_utils.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isnumeric.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_itohex.c\
		ft_itohex_ptr.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstclear.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstlast.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_max_int.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_percent_read1.c\
		ft_percent_read2.c\
		ft_printf.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strlst_addback.c\
		ft_strlst_clear.c\
		ft_strlst_del.c\
		ft_strlst_len.c\
		ft_strlst_merge.c\
		ft_strlst_new.c\
		ft_strlst_read.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strndup.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c

SOURCES = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# Compiler used for this project
CC = cc

# main rule called by default
all: $(NAME)

# rule for compile .c -> .o
objects/%.o : sources/%.c
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