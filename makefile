CC = gcc

RM = rm -rf

NAME = so_long

SRCS = main.c\
		

OBJ	= ${SRCS:.c=.o}


CFLAGS	= -g 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	make -C minilibx-linux
	$(CC) $(SRCS) ${CFLAGS} minilibx-linux/libmlx_Linux.a -lXext -lX11 -o $(NAME) 

all: ${NAME}

clean:
	${RM} ${OBJ} ${BONUS_OBJS}

fclean: clean
	make clean -C minilibx
	${RM} ${NAME} ${BONUS_NAME}

re: fclean all

.PHONY: all clean fclean re