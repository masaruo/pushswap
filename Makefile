# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:04:53 by mogawa            #+#    #+#              #
#    Updated: 2023/05/22 23:06:14 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
DEBUG 		=	dbg
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
FILES		=	push_swap push_swap_cmd1 push_swap_cmd2 push_swap_cmd3 ft_printf \
				ft_printf_nbr ft_printf_utils push_swap_radixsort \
				push_swap_make_stk push_swap_make_stk2 push_swap_algo push_swap_utils
SRCS_DIR	=	./srcs/
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS_FILES)))
INC			=	./includes/
OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

ifdef WITH_DEBUG
CFLAGS = -Wall -g3 -O0 -fsanitize=address
endif

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC) -c -o $@ $<

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

# $(DEBUG); $(OBJS)
# 	make  debug -C ./libft
# 	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(DEBUG)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean

re: fclean all

# .PHONY: all clean fclean re

# STORAGE
debug: fclean
	make $(NAME) WITH_DEBUG=1
.PHONY: debug all clean fclean re
