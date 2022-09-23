# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmasur <tmasur@mail.de>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 16:30:15 by tmasur            #+#    #+#              #
#    Updated: 2022/08/24 12:03:45 by renate           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===============================================================================
# Variables ====================================================================
#===============================================================================

NAME	:=	libft.a

# Directories ------------------------------------------------------------------
SRC_DIR	:=	src/
OBJ_DIR	:=	build/

# Files ------------------------------------------------------------------------
FILES	:=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c\
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
			ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
			ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRC		:=	$(addprefix $(SRC_DIR), $(FILES))
OBJ		:=	$(addprefix $(OBJ_DIR), $(FILES:.c=.o))

# Compiler ---------------------------------------------------------------------
CC			:=	gcc
DEBUG		:=	no
ifeq ($(DEBUG), yes)
FLAG		:=	-g -W
else
FLAG		:=	-Wall -Wextra -Werror
endif

# Colors -----------------------------------------------------------------------
DELETE		:= "\033[33m"
CREATE		:= "\033[32m"
SUCCESS		:= "\033[30;42m"
RESET_COLOR	:= "\033[0m"

#===============================================================================
# Rules ========================================================================
#===============================================================================

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo $(SUCCESS) "LIBFT >>> $(NAME) created and indexed" $(RESET_COLOR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAG) -c $< -o $@
	@echo $(CREATE) "LIBFT >>> $@ created" $(RESET_COLOR)

# Clean up ---------------------------------------------------------------------
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo $(DELETE) "LIBFT >>> $(NAME) deleted" $(RESET_COLOR)
	@echo $(DELETE) "LIBFT >>> $(OBJ_DIR) deleted" $(RESET_COLOR)

# Recompile --------------------------------------------------------------------
re: fclean all

# PHONY ------------------------------------------------------------------------
.PHONY: clean, all, fclean, re
