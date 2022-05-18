# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trozain <trozain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 14:07:27 by smichoud          #+#    #+#              #
#    Updated: 2022/05/16 19:22:55 by trozain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRCS		= srcs/ft_printf.c srcs/ft_part1.c srcs/ft_part2.c
OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

$(NAME) :	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all :		$(NAME)

clean :		
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
