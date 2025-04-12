NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
UTILS_DIR = utils

SRCS =	$(SRC_DIR)/algorithm.c \
		$(SRC_DIR)/free.c \
		$(SRC_DIR)/index.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/process_arg.c \
		$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/rotate_reverse.c \
		$(SRC_DIR)/sort_check.c \
		$(SRC_DIR)/sort_handler.c

UTILS = $(UTILS_DIR)/ft_atoi.c \
		$(UTILS_DIR)/ft_bzero.c \
		$(UTILS_DIR)/ft_calloc.c \
		$(UTILS_DIR)/ft_isdigit.c \
		$(UTILS_DIR)/ft_lstadd_back.c \
		$(UTILS_DIR)/ft_lstlast.c \
		$(UTILS_DIR)/ft_lstnew.c \
		$(UTILS_DIR)/ft_lstsize.c \
		$(UTILS_DIR)/ft_memset.c \
		$(UTILS_DIR)/ft_putchar_fd.c \
		$(UTILS_DIR)/ft_putstr_fd.c \
		$(UTILS_DIR)/ft_split.c \
		$(UTILS_DIR)/ft_strdup.c \
		$(UTILS_DIR)/ft_strlcpy.c \
		$(UTILS_DIR)/ft_strlen.c \
		$(UTILS_DIR)/ft_substr.c

OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)

INCLUDES = -I$(SRC_DIR) -I$(UTILS_DIR)

RM = rm -f

COLOR_MAGENTA		=	\033[0;95m
COLOR_LIGHT_GREEN   =   \033[0;92m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)
	@echo "$(COLOR_LIGHT_GREEN)Program created successfully!"

%.o: %.c
	@echo "$(COLOR_MAGENTA)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(COLOR_MAGENTA)"
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
