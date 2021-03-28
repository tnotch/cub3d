# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kirilltruhan <kirilltruhan@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 21:30:15 by tnotch            #+#    #+#              #
#    Updated: 2020/11/10 21:22:41 by kirilltruha      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= ft_strnstr.c ft_strrchr.c ft_memcmp.c ft_memchr.c ft_memmove.c \
		ft_memccpy.c ft_memcpy.c ft_isalnum.c ft_atoi.c ft_bzero.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c \
		ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_itoa.c ft_putnbr_fd.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_split.c ft_lstadd_back.c \
		ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstlast.c \
		ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstmap.c 

		
		
GCC		= gcc -Wall -Werror -Wextra

RM		= rm -f

OBGS	= ${SRCS:.c=.o}

MV		= mv -f 

NAME	= libft.a

${NAME}: all

all: 	
	${GCC} -c ${SRCS}
	ar rc ${NAME} ${OBGS}
clean:
		${RM} ${OBGS}
fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean	
