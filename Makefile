#===============================================================================
# Variables ====================================================================
#===============================================================================
NAME	:=	push_swap
LIBFT	?=	$(LIBFT_DIR)libft.a

# Directories ------------------------------------------------------------------
LIBFT_DIR	:=	lib/libft/
SRC_DIR		:=	src/
OBJ_DIR		:=	build/

# Files ------------------------------------------------------------------------
FILES	:=	main.c ft_merge_sort.c ft_stack_utils.c ft_node_utils.c \
			ft_validate_arguments.c
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

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) -o $@ $(LIBFT)
	@echo $(SUCCESS) "PUSH_SWAP >>> $(NAME) created" $(RESET_COLOR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAG) -c $< -o $@
	@echo $(CREATE) "PUSH_SWAP >>> $@ created" $(RESET_COLOR)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

# Clean up ---------------------------------------------------------------------
clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo $(DELETE) "PUSH_SWAP >>> $(NAME) deleted" $(RESET_COLOR)
	@echo $(DELETE) "PUSH_SWAP >>> $(OBJ_DIR) deleted" $(RESET_COLOR)

# Recompile --------------------------------------------------------------------
re: fclean all

# PHONY ------------------------------------------------------------------------
.PHONY: clean, all, fclean, re, debug
