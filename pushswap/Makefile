CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I./includes

OBJ_DIR = obj_dir

RM = rm -rf

NAME = push_swap

OUTPUTFLAG = -o

NORELINKFLAG = -c

MKDIR = mkdir -p

SRCS =\
	src/cost.c \
	src/do_move.c \
	src/initialization.c \
	src/input_check.c \
	src/input_check_utils.c \
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

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(OUTPUTFLAG) $(NAME)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(NORELINKFLAG) $< $(OUTPUTFLAG) $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
