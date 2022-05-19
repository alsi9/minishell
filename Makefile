# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ephantom <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 17:43:42 by ephantom          #+#    #+#              #
#   Updated: 2022/03/29 12:17:16 by                  ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRCS	=	src/main.c						builtin/echo_exit_pwd_env.c	lib/utils_libft_one.c\
			src/envp_to_list.c				builtin/cd_utils.c			lib/utils_libft_two.c\
			src/exec.c						builtin/builtin.c			lib/utils_libft_three.c\
			src/exec_signal.c				builtin/cd.c				lib/utils_libft_four.c\
			src/exec_utils.c				builtin/export.c			lib/ft_split.c\
			parser/parse_redirect_out.c		builtin/export_utils.c		utils/utils_free.c\
			parser/parse_space_redirect.c	builtin/unset.c				utils/utils.c\
			parser/parse_dollar.c			parser/parse_pipe.c			utils/list_new.c\
			parser/parse_quote.c			parser/parser.c				src/exec_one.c\
			parser/parse_redirect_in.c		parser/parse_utils.c		src/exec_final.c\
			parser/parse_heredoc.c			parser/parser_check.c		src/exec_utils_2.c

OBJS	=	${SRCS:%.c=%.o}

HEADER	=	includes/minishell.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I${HEADER}

RM		=	 rm -f

WLC		=	Welcome to Minishell

CLN		=	Cleaning Minishell

CYAN	=	\x1b[3;36m

END		=	\x1b[0m

.PHONY:		all clean fclean re

all:		${NAME}

%.o: 		%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS} ${HEADER}
			${CC} ${CFLAGS} -lreadline -g -L/Users/$(USER)/.brew/Cellar/readline/8.1.2/lib/ -I/Users/$(USER)/.brew/Cellar/readline/8.1.2/include -o ${NAME} ${OBJS}
##			${CC} ${CFLAGS} -lreadline -g -L/usr/local/Cellar/readline/8.1.2/lib/ -I/usr/local/Cellar/readline/8.1.2/include -o ${NAME} ${OBJS}
			@printf "${CYAN}${WLC}${END}\n"
clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
			@printf "${CYAN}${CLN}${END}\n"

re:			fclean all

norm:
			@norminette ${SRCS} ${HEADER}
