NAME		:= ping
CC		:= cc
CFLAGS		:= -g
OUTPUT_OPTION	= -MMD -MP -o $@

SOURCE		:= ping.c iputils_common.c
OBJS		= $(SOURCE:.c=.o)
DEPS		= $(SOURCE:.c=.d)

-include ${DEPS}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}


clean:
	rm -f *.o *.d

fclean: clean
	rm -f ${NAME}

ctags:
	ctags -R *
