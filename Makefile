# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:04:53 by mogawa            #+#    #+#              #
#    Updated: 2023/02/01 19:27:01 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs
RM			=	rm -f
FILES		=	ft_printf ft_printf_utils ft_printf_nbr
SRCS_DIR	=	./
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS		=	$(SRCS:.c=.o)

ifdef WITH_ASAN
CFLAGS += -g -O0 -fno-omit-frame-pointer
endif

ifdef WITH_LLDB
CFLAGS += -g3 -O0 -fsanitize=address -fno-omit-frame-pointer
endif

%.o : %.c 
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

asan: fclean
	make $(NAME) WITH_ASAN=1

lldb: fclean
	make $(NAME) WITH_LLDB=1

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: asan lldb all clean fclean re



