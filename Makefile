# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:04:53 by mogawa            #+#    #+#              #
#    Updated: 2023/05/23 21:38:34 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
LIBFT 		=	-C ./libft
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
FILES		=	push_swap push_swap_cmd1 push_swap_cmd2 push_swap_cmd3 ft_printf \
				ft_printf_nbr ft_printf_utils push_swap_radixsort \
				push_swap_make_stk push_swap_make_stk2 push_swap_algo push_swap_utils
SRCS_DIR	=	./srcs/
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
INC			=	./includes/
OBJS		=	$(SRCS:.c=.o)

ifdef DEBUG
CFLAGS	=	-Wall -g3 -O0 -fsanitize=address
LIBFT	=	debug -C ./libft
endif

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC) -c -o $@ $<

$(NAME): $(OBJS)
	make $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make $(LIBFT) fclean

re: fclean all

debug: fclean
	make $(NAME) DEBUG=1
	make clean

.PHONY: debug all clean fclean re
