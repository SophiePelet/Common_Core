# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   NAMES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
NAME		= philo
CFLAGS		= -Wall -Wextra -Werror -I${INCLUDE_DIR}
CC			= cc
INCLUDE_DIR	= .
OBJ_DIRS	= sources
# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   SOURCES                                  │
# └────────────────────────────────────────────────────────────────────────────┘
SRC_FILES	= src/main.c \
			  src/messages.c \
			  src/parsing.c \
			  src/utils.c \
			  src/init.c \
			  src/wrappers.c \
			  src/clean.c \
			  src/helpers.c \
			  src/routine.c

OBJ_FILES	= $(SRC_FILES:.c=.o)

LIBS		= philo.h
# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   RULES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
all : mkdir_obj_dirs ${NAME}

${NAME}: ${OBJ_FILES}
			${CC} -o $@ ${OBJ_FILES}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

mkdir_obj_dirs:
		@mkdir -p ${OBJ_DIRS}

clean:
		rm -f ${OBJ_FILES}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re