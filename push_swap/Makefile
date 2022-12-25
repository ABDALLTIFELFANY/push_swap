# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 11:46:39 by abelfany          #+#    #+#              #
#    Updated: 2022/12/25 22:26:16 by abelfany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h
SRCS = push_swap.c \
		ft_lstnew.c \
		check_case.c \
		ft_split.c \
		ft_strjoin.c \
		instructions.c \
		instructionsII.c \
		longest_sort.c \
		sort_stacks.c \
		sort_a_b.c \
		extantion.c \
		find_best_mv.c \
		return_to_sta.c
	
B_SRCS = checker.c \
		instructionsII_bonus.c \
		check_case_bonus.c \
		instructions_bonus.c \
		get_line_utils.c \
		ft_split_bonus.c \
		ft_strjoin_bonus.c \
		extantion_bonus.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
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

bonus:$(B_OBJS)
	gcc $(CFLAGS) $(B_OBJS) -o checker

%.o : %.c $(HEADER)
	cc $(CFLAGS) -c $< -I $(HEADER)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean:clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean
