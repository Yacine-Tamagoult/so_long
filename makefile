CC = gcc

RM = rm -rf

NAME = so_long

SRCS = 	main.c\
		mayalabeille/get_next_line.c \
		mayalabeille/get_next_line_utils.c \
		parsing_map.c \

OBJ	= ${SRCS:.c=.o}


CFLAGS	= -g 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	make -C minilibx-linux
	$(CC) $(SRCS) ${CFLAGS} minilibx-linux/libmlx_Linux.a -lXext -lX11 -o $(NAME) 

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	make clean -C minilibx-linux
	make clean -C so_long
	${RM} ${NAME} 

re: fclean all

.PHONY: all clean fclean re