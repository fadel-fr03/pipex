# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 16:47:51 by fal-frou          #+#    #+#              #
#    Updated: 2024/08/22 18:23:37 by fal-frou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source Files
SRC     =	src/exec_utils.c src/pipex.c src/utils.c
B_SRC   =	src_bonus/exec_utils.c src_bonus/handle_errors.c src_bonus/here_doc.c \
			src_bonus/pipex_bonus.c src_bonus/utils_bonus.c

# Object Files
OBJS    = ${SRC:.c=.o}
B_OBJS  = ${B_SRC:.c=.o}

# Includes
INCLUDES    = -I./inc/
B_INCLUDES  = -I./inc_bonus/

# Libft Directory
LIBDIR  = ./libft/ 

# Variables
NAME    = pipex
RM      = rm -f
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

# Default Target
all:	${NAME}

# Linking the pipex Executable
${NAME}:	${OBJS}
	${RM} ${B_OBJS}
	make -C ${LIBDIR}
	$(CC) $(CFLAGS) ${INCLUDES} ${OBJS} -L${LIBDIR} -lft -o $(NAME)

# Linking the bonus pipex Executable
bonus:	${B_OBJS}
	${RM} ${OBJS}
	make -C ${LIBDIR}
	$(CC) $(CFLAGS) ${B_INCLUDES} ${B_OBJS} -L${LIBDIR} -lft -o $(NAME)

# Compilation Rule
%.o: %.c
	$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $@

# Bonus Compilation Rule
src_bonus/%.o: src_bonus/%.c
	$(CC) $(CFLAGS) ${B_INCLUDES} -c $< -o $@

# Delete Mandatory Object Files
clean_mandatory:
	${RM} ${OBJS}
	make -C ${LIBDIR} clean

# Delete Bonus Object Files
clean_bonus:
	${RM} ${B_OBJS}
	make -C ${LIBDIR} clean

# Delete All Object Files
clean: clean_mandatory clean_bonus

# Delete Mandatory Object Files and Executable
fclean_mandatory: clean_mandatory
	${RM} ${NAME}
	make -C ${LIBDIR} fclean

# Delete Bonus Object Files and Executable
fclean_bonus: clean_bonus
	${RM} ${NAME} 
	make -C ${LIBDIR} fclean

# Delete ALl Object Files and Executables
fclean: fclean_mandatory fclean_bonus

# Rebuild Mandatory pipex
re: fclean all

# Rebuild Bonus pipex
re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus fclean_bonus fclean_mandatory clean_bonus clean_mandatory bonus
