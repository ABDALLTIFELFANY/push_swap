# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 11:46:39 by abelfany          #+#    #+#              #
#    Updated: 2022/12/31 17:26:00 by abelfany         ###   ########.fr        #
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
		return_to_sta.c \
		ft_atoi.c \
		count_mov.c
	
B_SRCS = bonus/checker.c \
		bonus/instructionsII_bonus.c \
		bonus/check_case_bonus.c \
		bonus/instructions_bonus.c \
		bonus/get_line_utils.c \
		bonus/ft_split_bonus.c \
		bonus/ft_strjoin_bonus.c \
		bonus/get_line.c \
		bonus/extantion_bonus.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra  -g
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
	cc $(CFLAGS) -c $< -I $(HEADER) -o $@

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean:clean
	@$(RM) $(NAME) checker

re: fclean all

.PHONY: all re fclean clean
