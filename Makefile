# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 16:54:49 by dalba             #+#    #+#              #
#    Updated: 2020/12/11 16:50:42 by dalba-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #

# This is a minimal set color codes
_END		=	\033[0m
_BOLD		=	\033[1m
_UNDER		=	\033[4m
_REV		=	\033[7m

# Colors
_GREY		=	\033[30m
_RED		=	\033[0;31m
_GREEN		=	\033[0;32m
_YELLOW		=	\033[33m
_BLUE		=	\033[34m
_PURPLE		=	\033[35m
_CYAN		=	\033[1;36m
_WHITE		=	\033[37m

# Inverted, i.e. colored backgrounds
_IGREY		=	\033[40m
_IRED		=	\033[41m
_IGREEN		=	\033[42m
_IYELLOW	=	\033[43m
_IBLUE		=	\033[44m
_IPURPLE	=	\033[45m
_ICYAN		=	\033[46m
_IWHITE		=	\033[47m

# **************************************************************************** #

# MACROS #

NAME = libasm.a

CC = gcc

CFLAGS = -I./includes -Wall -Werror -Wextra 

NASM = @nasm

NFLAGS = -felf64 -I./includes

AR = ar rc

SRC_DIR = srcs/

INC_DIR = includes/

OBJ_DIR = objects/

SRC =	ft_strcmp.s ft_strlen.s ft_strcpy.s ft_strdup.s ft_read.s ft_write.s

SRCS = $(addprefix ${SRC_DIR},${SRC})

OBJ = $(addprefix ${OBJ_DIR}, ${SRC:.s=.o})

SRC_B = ft_strcmp.s ft_strlen.s ft_strcpy.s ft_strdup.s ft_read.s ft_write.s \
		ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s ft_atoi_base.s \

SRCS_B = $(addprefix ${SRC_DIR},${SRC_B})

OBJ_B = $(addprefix ${OBJ_DIR}, ${SRC_B:.s=.o})

# **************************************************************************** #

# RULES #

all:		${NAME}

${NAME} :	${OBJ}
			@echo "$(_GREEN) All files compiled. $(_END)✅"
			@${AR} ${NAME} ${OBJ}
			@ranlib ${NAME}
			@echo "$(_GREEN) Library '$(NAME)' compiled. $(_END)✅"

${OBJ_DIR}%.o: ${SRC_DIR}%.s
			@mkdir -p ${OBJ_DIR}
			${NASM} ${NFLAGS} -o $@ -s $<

bonus:		${OBJ_B}
			@echo "$(_PURPLE) Updating Library... $(_END)"
			@${AR} ${NAME} $^
			@ranlib ${NAME}
			@echo "$(_PURPLE) Library '$(NAME)' with bonus compiled. $(_END)✅"

clean:
			@rm -rf ${OBJ_DIR}
			@echo "$(_RED)'$(OBJ_DIR)' has been deleted. $(_END)🗑️"

fclean:		clean
			@rm -f ${NAME}
			@rm -f bonus_test
			@rm -f tester
			@rm -f atoi_test
			@rm -f tester.txt
			@echo "$(_RED)'$(NAME)' and 'Executables' has been deleted. $(_END)🗑️"

re:			fclean all

# **************************************************************************** #

# TEST #

run:		
			@clear
			@clang -I./test -no-pie test/main.c test/ft_strlen_test.c test/ft_strcpy_test.c test/ft_strcmp_test.c test/ft_strdup_test.c \
			test/ft_write_test.c test/ft_read_test.c -o tester libasm.a
			@./tester

runbonus:
			@clear && gcc -I./test -no-pie test/atoi_test.c -o atoi_test libasm.a && ./atoi_test
			@clang -I./test -no-pie test/main_bonus.c test/linked_list_test.c -o bonus_test libasm.a && ./bonus_test

.PHONY:		clean, fclean, re, all