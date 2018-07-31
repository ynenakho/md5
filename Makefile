# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 18:23:28 by ynenakho          #+#    #+#              #
#    Updated: 2018/03/19 18:26:12 by ynenakho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
SRC = main.c get_opt.c hashing.c ft_ssl_md5.c global_vars.c
OBJ = main.o get_opt.o hashing.o ft_ssl_md5.o global_vars.o

DEPS = ft_ssl_md5.h
LIBS = ./libft/libft.a


all: libftcreate $(NAME)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) $(LIBS)

libftcreate:
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) clean -C ./libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all
