# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 10:47:24 by rficht            #+#    #+#              #
#    Updated: 2023/08/22 13:23:06 by rficht           ###   ########.fr        #
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
FILES =	ft_2lst_utils.c\
		ft_2lst_utils2.c\
		ft_abs.c\
		ft_atoi.c\
		ft_atouc.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_fabsmax.c\
		ft_freenull.c\
		ft_freestr.c\
		ft_freetab.c\
		ft_inc_value.c\
		ft_is_in.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isint.c\
		ft_isprint.c\
		ft_isspace.c\
		ft_itoa.c\
		ft_isuchar.c\
		ft_lst_to_strtab.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstclear.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstdeltop.c\
		ft_lstiter.c\
		ft_lstlast.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_max.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_min.c\
		ft_printf.c\
		ft_printfutils.c\
		ft_printstrtab.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_base.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_quotesplit.c\
		ft_sign.c\
		ft_split.c\
		ft_split_by_lst.c\
		ft_sstrlen.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strdelchar.c\
		ft_strdup.c\
		ft_strequal.c\
		ft_strfjoin.c\
		ft_strhowmany.c\
		ft_strinsert.c\
		ft_strisdigit.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlastof.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmanyjoin.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strresize.c\
		ft_strshortenby.c\
		ft_strtrim.c\
		ft_strtrunc.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_uitoa.c\
		ft_where_is.c\
		get_next_line.c\
		get_next_line_utils.c



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