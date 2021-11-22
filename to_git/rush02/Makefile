NAME	= rush-02
SRCS	= main.c libstr.c args.c check_nb.c print.c tab.c
OBJS	= ${SRCS:.c=.o}
HEADER	= rush.h

CC		= cc
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f

${NAME}:	${SRCS}
			${CC} -c ${CFLAGS} ${SRCS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -I ${HEADER}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}

.PHONY:		clean
			fclean
			all
			re
