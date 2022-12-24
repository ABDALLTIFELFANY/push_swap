# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 11:46:39 by abelfany          #+#    #+#              #
#    Updated: 2022/12/24 12:46:22 by abelfany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h
SRCS = push_swap.c \
		ft_lstnew.c \
		check_case.c \
		check_sort.c \
		ft_split.c \
		ft_strjoin.c \
		instructions.c \
		instructionsII.c \
		longest_sort.c \
		sort_stacks.c \
		sort_a_b.c \
		extantion.c \
		return_to_sta.c \
		ft_strcmp.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = @ar -rc

all: $(NAME)

		@echo "██████╗░██╗░░░██╗░██████╗██╗░░██╗░██████╗░██╗░░░░░░░██╗░█████╗░██████╗░"
		@echo "██╔══██╗██║░░░██║██╔════╝██║░░██║██╔════╝░██║░░██╗░░██║██╔══██╗██╔══██╗"
		@echo "██████╔╝██║░░░██║╚█████╗░███████║╚█████╗░░╚██╗████╗██╔╝███████║██████╔╝"
		@echo "██╔═══╝░██║░░░██║░╚═══██╗██╔══██║░╚═══██╗░░████╔═████║░██╔══██║██╔═══╝░"
		@echo "██║░░░░░╚██████╔╝██████╔╝██║░░██║██████╔╝░░╚██╔╝░╚██╔╝░██║░░██║██║░░░░░"
		@echo "╚═╝░░░░░░╚═════╝░╚═════╝░╚═╝░░╚═╝╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░░░░"
$(NAME):$(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	cc $(CFLAGS) -c $< -I $(HEADER)
clean:
	$(RM) $(OBJS)

fclean:clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean
