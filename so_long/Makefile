###########################################
#### NAMES
NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror -I${LIBFT_DIR} -I${MLX_DIR} -I${INCLUDE_DIR} ##-L/usr/lib
CC			= cc
LIBFT_DIR	= ./libft/
LIBFT		= ${LIBFT_DIR}libft.a
MLX_DIR		= ./mlx_linux/
MLX			= ${MLX_DIR}libmlx_Linux.a
MLX_FLAGS	= -L${MLX_DIR} -lmlx -lXext -lX11 -lm
INCLUDE_DIR	= .
OBJ_DIRS	= parsing

###########################################
#### SOURCES
SRC_FILES	= parsing/parse_map.c \
			  parsing/main.c \
			  parsing/map_check_shape.c \
			  parsing/map_check_elem.c \
			  parsing/path_finding.c \
			  parsing/visited_helper.c \
			  parsing/queue_helper.c \
			  parsing/map_helper.c \

OBJ_FILES	= $(SRC_FILES:.c=.o)

LIBS		= so_long.h
###########################################
#### RULES
all : mkdir_obj_dirs ${NAME}

${NAME}: ${OBJ_FILES} ${LIBFT} ${MLX}
			${CC} -o $@ ${OBJ_FILES} ${LIBFT} ${MLX_FLAGS}

${LIBFT}:
			@$(MAKE) -C ${LIBFT_DIR}

${MLX}:
			@$(MAKE) -C ${MLX_DIR}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

mkdir_obj_dirs:
		@mkdir -p ${OBJ_DIRS}

clean:
		rm -f ${OBJ_FILES}
		@make clean -C ${LIBFT_DIR}
		@make clean -C ${MLX_DIR}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re