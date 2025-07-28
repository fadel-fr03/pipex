#		Source Files		#

SRCS	=	${wildcard src/*.c}

#		Includes		#
INCLUDES	= -I inc/

#		Object Files		#
OBJS	=	${SRCS:.c=.o}

# 		Variables		#

NAME	=	libft.a

AR		=	ar rcs

RM		=	rm -f

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror ${INCLUDES}

#		Default Target		#
all:	${NAME}

#		Linking the library		#
${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}


#		Compilation Rule		#
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
	
#		Cleaning Object Files		#
clean:
	${RM} ${OBJS} ${BONUS_OBJS}

#		Cleaning Object Files and the library		#
fclean:		clean
	${RM} ${NAME}

#		Rebuild Everything		#
re:	fclean all

.PHONY:	all clean fclean re bonus
