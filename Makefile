# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 09:04:21 by sergiopax         #+#    #+#              #
#    Updated: 2022/02/21 09:31:00 by sergiopax        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c main_process_utils.c get_tokens.c get_tokens_utils.c get_io_files.c \
libft_utils.c construct_command_paths.c get_io_files_utils.c get_relative_path.c execute_builtins.c \
redirection.c redirection_utils.c pipes.c echo.c pwd.c env.c manage_environment_variables.c \
expand_variables.c expand_variables_utils.c export.c export_utils.c libft_utils_2.c unset.c cd.c \
get_here_document.c closed_quotes.c free_memory.c configure_sigaction.c libft_utils_3.c \
goes_crazy.c goes_crazy_2.c check_tokens.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OBJECTS 	= ${SRC:.c=.o}

OBJECTS_DIR 	= OBJECTS/
OBJECTS_IN_DIR 	= ${addprefix ${OBJECTS_DIR}, ${OBJECTS}}

NAME = minishell

${NAME}:	${OBJECTS_IN_DIR} minishell.h
	${CC} ${OBJECTS_IN_DIR} -o ${NAME} -lreadline

$(OBJECTS_DIR)%.o : %.c minishell.h
	mkdir -p ${OBJECTS_DIR}
	cp ./minishell.h ./${OBJECTS_DIR} 
	${CC} -c $< -o $@ -lreadline

RM = rm -rf

all: $(NAME)

clean:
	${RM} ${OBJECTS_DIR}

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY:         all clean fclean re
