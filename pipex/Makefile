# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   NAMES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
NAME			= pipex
CFLAGS			= -Wall -Wextra -Werror -I${INCLUDE_DIR} -I${LIBFT_DIR}
CC				= cc
LIBFT_DIR		= ./libft/
LIBFT			= ${LIBFT_DIR}libft.a
INCLUDE_DIR		= .
OBJ_DIRS		= sources bonus
# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   SOURCES                                  │
# └────────────────────────────────────────────────────────────────────────────┘
SRC_FILES		= sources/main.c \
				  sources/pipex_utils.c \
				  sources/parsing.c \

OBJ_FILES		= $(SRC_FILES:.c=.o)

BONUS_FILES		= bonus/helpers_bonus.c \
				  bonus/cleaner_bonus.c \
				  bonus/main_bonus.c \
				  bonus/parsing_bonus.c \
				  bonus/utils_bonus.c \

BONUS_OBJ		= $(BONUS_FILES:.c=.o)

LIBS			= pipex.h pipex_bonus.h
# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   RULES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
all	: mkdir_obj_dirs ${NAME}

${NAME}: ${OBJ_FILES} ${LIBFT}
			${CC} -o ${NAME} ${OBJ_FILES} ${LIBFT}

bonus: .bonus_built

.bonus_built: ${BONUS_OBJ} ${LIBFT}
		@mkdir -p ${OBJ_DIRS}
		${CC} ${CFLAGS} -o ${NAME} ${BONUS_OBJ} ${LIBFT}
		@touch .bonus_built

${LIBFT}:
			@$(MAKE) -C ${LIBFT_DIR}

%.o: %.c ${LIBS}
	${CC} ${CFLAGS} -c $< -o $@

mkdir_obj_dirs:
		@mkdir -p ${OBJ_DIRS}

clean:
		rm -f ${OBJ_FILES} ${BONUS_OBJ} .bonus_built

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re