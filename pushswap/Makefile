CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDE = -I./includes

INCLUDE_BONUS = -I./push_swap_bonus/includes


OBJ_DIR = obj_dir

BONUS_OBJ_DIR = push_swap_bonus/obj_dir_bonus

RM = rm -rf

NAME = push_swap

BONUS_NAME = checker

LIBFT = ./libft/libft.a

LIBFT_DIR = ./libft

OUTPUTFLAG = -o

NORELINKFLAG = -c

MKDIR = mkdir -p

SRCS =\
	src/cost.c \
	src/do_move.c \
	src/initialization.c \
	src/input_check.c \
	src/main.c \
	src/position.c \
	src/push.c \
	src/reverse_rotate.c \
	src/rotate.c \
	src/sort.c \
	src/sort_tiny.c \
	src/stack.c \
	src/swap.c \
	src/utils.c

BONUS_SRC =\
	push_swap_bonus/src/initialization_bonus.c \
	push_swap_bonus/src/input_check_bonus.c \
	push_swap_bonus/src/push_bonus.c \
	push_swap_bonus/src/reverse_rotate_bonus.c \
	push_swap_bonus/src/rotate_bonus.c \
	push_swap_bonus/src/stack_bonus.c \
	push_swap_bonus/src/utils_bonus.c \
	push_swap_bonus/src/swap_bonus.c \
	push_swap_bonus/src/checker_bonus.c

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

OBJS_BONUS = $(addprefix $(BONUS_OBJ_DIR)/, $(notdir $(BONUS_SRC:.c=.o)))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(OUTPUTFLAG) $(NAME)

bonus: $(LIBFT) $(OBJS_BONUS) | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(OUTPUTFLAG) $(BONUS_NAME)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(NORELINKFLAG) $< $(OUTPUTFLAG) $@

$(BONUS_OBJ_DIR)/%.o: push_swap_bonus/src/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_BONUS) $(NORELINKFLAG) $< $(OUTPUTFLAG) $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	$(MKDIR) $(BONUS_OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
