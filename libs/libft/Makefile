# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 18:17:56 by casubmar          #+#    #+#              #
#    Updated: 2020/05/06 16:49:15 by casubmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNC = ft_atoi ft_isalpha ft_memccpy\
ft_memmove ft_strlcat ft_strnstr ft_bzero\
ft_isascii ft_memchr ft_memset ft_strlcpy\
ft_strrchr ft_calloc ft_isdigit ft_memcmp\
ft_strchr ft_strlen ft_tolower ft_isalnum\
ft_isprint ft_memcpy ft_strdup ft_strncmp\
ft_toupper ft_substr ft_strjoin ft_strtrim\
ft_split ft_itoa ft_strmapi ft_putchar_fd\
ft_putstr_fd ft_putendl_fd ft_putnbr_fd

BONUSE_F = ft_lstnew ft_lstadd_front ft_lstsize\
ft_lstlast ft_lstadd_back ft_lstdelone\
ft_lstclear ft_lstiter ft_lstmap

BONUSE = $(addsuffix .c, $(BONUSE_F))
SRC = $(addsuffix .c, $(FUNC))
OBJ = $(addsuffix .o, $(FUNC))
OBJ_B = $(addsuffix .o, $(BONUSE_F))
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus clean_obj

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "-----------Lib create-----------"
	@ranlib $(NAME)

%.o: %.c
	@gcc -I. $(FLAGS) -o $@ -c $<

bonus: $(OBJ_B) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(OBJ_B)
	@echo "-----------Bonuse Lib create-----------"
	@ranlib $(NAME)

clean_obj:
	@rm -f $(OBJ_B)

clean: clean_obj
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all