NAME		:= ping

include makefile.conf

OBJS		= $(SOURCE:.c=.o)
DEPS		= $(SOURCE:.c=.d)

-include ${DEPS}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}


clean:
	rm -f ${OBJS} ${DEPS}

fclean: clean
	rm -f ${NAME}

ctags:
	ctags -R *

help:
	-@echo "clean:  delete .o and .d files"
	-@echo "fclean: execute make clean and delete binaries"
	-@echo "ctags:  generates vim tags"

.PHONY: all clean fclean ctags help
