# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/26 18:44:42 by whumfrey          #+#    #+#              #
#    Updated: 2019/02/26 19:05:03 by whumfrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c read.c instruments.c instruments_2.c chek.c solver.c

OBJ = $(SRC:.c=.o)

LIBFT = includes/libft.a

HEADER = -c -I fillit.h

all: $(NAME)

$(OBJ): %.o: %.c
		@gcc -c -Wall -Werror -Wextra -I includes/ $< -o $@

$(LIBFT):
	@make -C includes

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	@make -C includes clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C includes fclean

re: fclean all