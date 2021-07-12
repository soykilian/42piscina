
NAME = rush-02

SRCS = args.c aux.c aux2.c mapping.c main.c

OBJS = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
		cc -o ${NAME} ${SRCS} -Iincludes ${FLAGS}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

debug:
		@$ gcc $(FLAGS) -o $(NAME) $(SOURCES) -g;

re:		fclean all
