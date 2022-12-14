# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 11:07:38 by lel-khou          #+#    #+#              #
#    Updated: 2022/12/14 10:58:16 by lel-khou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -pthread -Wall -Werror -Wextra

HEADER = philo.h

RM = rm -f

NAME = philo

SRC = main.c routine.c utils.c error.c init.c threads.c

OBJS = $(SRC:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
