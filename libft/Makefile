# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   NAMES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
NAME			= libft.a
CFLAGS			= -Wall -Wextra -Werror -I${INCLUDE_DIR}
CC				= cc
AR				= ar
ARFLAGS			= rcs
INCLUDE_DIR		= .
OBJ_DIRS		= other mem put strings lists my_printf gnl
# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   SOURCES                                  │
# └────────────────────────────────────────────────────────────────────────────┘
SRC_FILES		=	other/ft_atoi.c \
					other/ft_bzero.c \
					other/ft_calloc.c \
					strings/ft_isalnum.c \
					strings/ft_isalpha.c \
					strings/ft_isascii.c \
					strings/ft_isdigit.c \
					strings/ft_isprint.c \
					other/ft_itoa.c \
					mem/ft_memchr.c \
					mem/ft_memcmp.c \
					mem/ft_memcpy.c \
					mem/ft_memmove.c \
					mem/ft_memset.c \
					put/ft_putchar_fd.c \
					put/ft_putendl_fd.c \
					put/ft_putnbr_fd.c \
					put/ft_putstr_fd.c \
					strings/ft_split.c	\
					strings/ft_strchr.c \
					strings/ft_strdup.c \
					strings/ft_striteri.c \
					strings/ft_strjoin.c \
					strings/ft_strlcat.c \
					strings/ft_strlcpy.c \
					strings/ft_strlen.c \
					strings/ft_strmapi.c \
					strings/ft_strncmp.c \
					strings/ft_strnstr.c \
					strings/ft_strrchr.c \
					strings/ft_strtrim.c \
					strings/ft_substr.c \
					strings/ft_tolower.c \
					strings/ft_toupper.c \
					my_printf/ft_printf.c \
					my_printf/ft_format.c \
					my_printf/ft_pointer.c \
					my_printf/ft_putnbr_hexl.c \
					my_printf/ft_putnbr_hexu.c \
					my_printf/ft_putnbr_unsigned.c \
					my_printf/ft_putnbr.c \
					my_printf/ft_putstr.c \
					my_printf/ft_putchar.c \
					gnl/get_next_line.c \
					gnl/get_next_line_utils.c \

OBJ_FILES		=	$(SRC_FILES:.c=.o)

BON_SRC			=	lists/ft_lstadd_back_bonus.c \
					lists/ft_lstadd_front_bonus.c \
					lists/ft_lstnew_bonus.c \
					lists/ft_lstsize_bonus.c \
					lists/ft_lstlast_bonus.c \
					lists/ft_lstdelone_bonus.c \
					lists/ft_lstclear_bonus.c \
					lists/ft_lstiter_bonus.c \
					lists/ft_lstmap_bonus.c \

BON_OBJ			=	$(BON_SRC:.c=.o)

LIBS			= libft.h
# ┌────────────────────────────────────────────────────────────────────────────┐
# │                                   RULES                                    │
# └────────────────────────────────────────────────────────────────────────────┘
all: mkdir_obj_dirs ${NAME}

${NAME}: ${OBJ_FILES}
			${AR} ${ARFLAGS} ${NAME} ${OBJ_FILES}

bonus: mkdir_obj_dirs ${BON_OBJ}
			${AR} ${ARFLAGS} ${NAME} ${BON_OBJ}

%.o: %.c ${LIBS}
		${CC} ${CFLAGS} -c $< -o $@

mkdir_obj_dirs:
		@mkdir -p ${OBJ_DIRS}

clean:
		rm -f ${OBJ_FILES} ${BON_OBJ}

fclean: clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re