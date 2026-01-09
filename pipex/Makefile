# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   NAMES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
NAME			= pipex
CFLAGS			= -Wall -Wextra -Werror -I${INCLUDE_DIR} -I${LIBFT_DIR}
CC				= cc
LIBFT_DIR		= ./libft/
LIBFT			= ${LIBFT_DIR}libft.a
INCLUDE_DIR		= .
OBJ_DIRS		= sources
# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   SOURCES                                  │
# └────────────────────────────────────────────────────────────────────────────┘
SRC_FILES		= sources/main.c \
				  sources/pipex_utils.c \
				  sources/parsing.c \

OBJ_FILES		= $(SRC_FILES:.c=.o)

LIBS			= pipex.h
# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   RULES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
all	: mkdir_obj_dirs ${NAME}

${NAME}: ${OBJ_FILES} ${LIBFT}
			${CC} -o ${NAME} ${OBJ_FILES} ${LIBFT}

${LIBFT}:
			@$(MAKE) -C ${LIBFT_DIR}

%.o: %.c ${LIBS}
	${CC} ${CFLAGS} -c $< -o $@

mkdir_obj_dirs:
		@mkdir -p ${OBJ_DIRS}

clean:
		rm -f ${OBJ_FILES}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re