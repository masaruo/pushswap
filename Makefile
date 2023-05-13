# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:04:53 by mogawa            #+#    #+#              #
#    Updated: 2023/05/13 14:22:19 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pushswap
CC			=	cc
# CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-Wall
RM			=	rm -f
FILES		=	push_swap push_swap_cmd1 push_swap_cmd2 push_swap_cmd3 ft_printf \
				ft_printf_nbr ft_printf_utils push_swap_errors \
				push_swap_make_stk push_swap_algo
# BONUS_FILES	=	pipex_bonus get_next_line get_next_line_utils pipex_bonus_utils
SRCS_DIR	=	./srcs/
# BONUS_DIR	=	./srcs/
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS_FILES)))
INC			=	./includes/
OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

# ifdef WITH_BONUS
# OBJS += $(OBJS_B)
# endif

ifdef WITH_DEBUG
CFLAGS = -Wall -g3 -O0 -fsanitize=address
endif

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC) -c -o $@ $<

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

$(NAME)_bonus: $(OBJS_B)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS_B) ./libft/libft.a -o $(NAME)

bonus: $(NAME)_bonus

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)
#$(RM) ./bonus_files/$(OBJS_B)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
#$(RM) $(NAME)_bonus
	make -C ./libft fclean

re: fclean all

# .PHONY: all clean fclean re

# STORAGE
debugbonus: fclean
	make bonus WITH_DEBUG=1
debug: fclean
	make $(NAME) WITH_DEBUG=1
.PHONY: debug all clean fclean re debugbonus
