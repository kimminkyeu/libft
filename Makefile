# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 15:31:26 by minkyeki          #+#    #+#              #
#    Updated: 2022/03/22 16:50:46 by minkyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

CC				= gcc

CFLAGS			= -Werror -Wextra -Wall

SRCS 			= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
				  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
				  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				  ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
				  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SRCS2 			= ft_isspace.c 

SRCS_BONUS 		= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS 			= ${SRCS:.c=.o}
OBJS2 			= ${SRCS2:.c=.o}
OBJS_MANDATORY 	= ${OBJS} ${OBJS2}
OBJS_BONUS 		= ${SRCS_BONUS:.c=.o}

ifdef WITH_BONUS
	OBJS_RESULT = ${OBJS_MANDATORY} ${OBJS_BONUS}
else
	OBJS_RESULT = ${OBJS_MANDATORY}
endif

all: ${NAME}

${NAME}: ${OBJS_RESULT}
	ar rcs ${NAME} $^

.c.o:
	${CC} ${CFLAGS} -c $^ -o $@

bonus:
	@make WITH_BONUS=1

clean:
	rm -f ${OBJS} ${OBJS2} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
