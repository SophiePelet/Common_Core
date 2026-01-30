# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   NAMES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
NAME			= push_swap
CFLAGS			= -Wall -Wextra -Werror -I${LIBFT_DIR} -I${INCLUDE_DIR}
CC				= cc
LIBFT_DIR		= ./libft/
LIBFT			= ${LIBFT_DIR}libft.a
OBJ_DIRS		= sources sources/operations
INCLUDE_DIR		= .

# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   SOURCES                                  │
# └────────────────────────────────────────────────────────────────────────────┘
SRC_FILES		= sources/main.c \
				  sources/parsing.c \
				  sources/lists.c \
				  sources/utils.c \
				  sources/helpers.c \
				  sources/helpers2.c \
				  sources/operations/both_stacks.c \
				  sources/operations/push.c \
				  sources/operations/rotate.c \
				  sources/operations/swap.c \
				  sources/calculate_cost.c \
				  sources/sorting_small.c \
				  sources/sorting.c \

OBJ_FILES		= ${SRC_FILES:.c=.o}

# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   RULES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
all: ${NAME}

${NAME}: ${OBJ_FILES} ${LIBFT}
			${CC} -o $@ ${OBJ_FILES} ${LIBFT}

${LIBFT}:
		@$(MAKE) -C ${LIBFT_DIR}

%o: %.c
	${CC} ${CFLAGS} -c $< -o $@
	@mkdir -p ${OBJ_DIRS}

clean:
	rm -f ${OBJ_FILES}
	@make clean -C ${LIBFT_DIR}

fclean: clean
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
