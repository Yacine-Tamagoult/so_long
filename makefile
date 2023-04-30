CC = gcc

RM = rm -rf

NAME = so_long

SRCS = 	main.c\
		win.c \
		parsing_map_2.c \
		parsing_map_3.c \
		parsing_map.c \
		mayalabeille/get_next_line.c \
		mayalabeille/get_next_line_utils.c \
		init_Struct.c \
		plusdeplace.c \
		


OBJ	= ${SRCS:.c=.o}


CFLAGS	= -g -Wextra -Werror -Wall

PRINTF = ft_printf/libftprintf.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	make -C minilibx-linux
	make -C ft_printf
	$(CC) $(SRCS) ${CFLAGS} $(PRINTF) minilibx-linux/libmlx_Linux.a -lXext -lX11 -o $(NAME) 

all: ${NAME}

clean:
	${RM} ${OBJ}
	make clean -C minilibx-linux

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re