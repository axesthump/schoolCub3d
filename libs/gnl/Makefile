# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/07 16:38:21 by casubmar          #+#    #+#              #
#    Updated: 2020/08/07 17:07:27 by casubmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
FUNC = get_next_line  get_next_line  get_next_line_utils
SRC = $(addsuffix .c, $(FUNC))
OBJ = $(addsuffix .o, $(FUNC))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "-----------Lib create-----------"
	@ranlib $(NAME)

%.o: %.c
	@gcc -I. $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all