# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 15:04:02 by yelazrak          #+#    #+#              #
#    Updated: 2019/05/31 01:58:20 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell

SRCS = mini.c \
		ft_cmd.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = shell.h

CC = gcc -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@make  -C libft
	@$(CC) $(SRCS) libft/libft.a -I $(INCLUDES) -o  $(NAME)
clean :
	@rm -rf $(OBJS)
	@make clean -C libft
fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
re: fclean all
