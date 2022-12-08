# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 11:46:39 by abelfany          #+#    #+#              #
#    Updated: 2022/12/05 17:09:15 by abelfany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = huh.a
HEADER = push_swap.h
SRCS = push_swap.c \
		newlst.c \
		check_case.c \
		check_sort.c \
		ft_split.c \
		sortadd.c\
		ft_strjoin.c \
		ft_strcmp.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = @ar -rc

all: $(NAME)

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	cc $(CFLAGS) -c $< -I $(HEADER)
clean:
	$(RM) $(OBJS)

fclean:clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean
