# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:04:53 by mogawa            #+#    #+#              #
#    Updated: 2023/05/06 18:38:01 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	cc
# CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-Wall
RM			=	rm -f
FILES		=	push_swap push_swap_cmd1 push_swap_cmd2
# BONUS_FILES	=	pipex_bonus get_next_line get_next_line_utils \
# 				pipex_bonus_utils
SRCS_DIR	=	./srcs/
# BONUS_DIR	=	./bonus_files/
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B		=	$(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
INC			=	./includes/
OBJS		=	$(SRCS:.c=.o)
# OBJS_B		=	$(SRCS_B:.c=.o)

ifdef WITH_DEBUG
CFLAGS += -g3 -O0 -fsanitize=address
endif

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC) -c -o $@ $<

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	$(RM) ./bonus_files/$(OBJS_B)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME)_bonus
	make -C ./libft fclean

re: fclean all

# .PHONY: all clean fclean re

# STORAGE
debug: fclean
	make debug -C ./libft
	make $(NAME) WITH_DEBUG=1
.PHONY: debug all clean fclean re debugbonus