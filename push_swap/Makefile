# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   NAMES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
NAME			= push_swap
NAME_BONUS		= checker
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

BONUS_SRC_FILES	= bonus/checker_bonus.c \
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

BONUS_OBJ_FILES	= ${BONUS_SRC_FILES:.c=.o}

# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   RULES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
all: ${NAME}

${NAME}: ${OBJ_FILES} ${LIBFT}
	${CC} -o $@ ${OBJ_FILES} ${LIBFT}

${NAME_BONUS}: ${BONUS_OBJ_FILES} ${LIBFT}
	${CC} -o $@ ${BONUS_OBJ_FILES} ${LIBFT}

bonus: .bonus_built

.bonus_built: ${NAME_BONUS}
	@touch .bonus_built

${LIBFT}:
	@$(MAKE) -C ${LIBFT_DIR}

%.o: %.c
	@mkdir -p ${OBJ_DIRS}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ_FILES} ${BONUS_OBJ_FILES} .bonus_built
	@make clean -C ${LIBFT_DIR}

fclean: clean
			rm -f ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re
