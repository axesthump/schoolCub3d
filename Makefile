# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/07 16:12:25 by casubmar          #+#    #+#              #
#    Updated: 2020/09/07 20:42:20 by casubmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
HEADERS = /include
FOLDER_SRCS = ./srcs/
FUNC =	$(FOLDER_SRCS)cub3d $(FOLDER_SRCS)ft_pixel_put\
		$(FOLDER_SRCS)ft_get_map_and_player\
		$(FOLDER_SRCS)ft_key_press $(FOLDER_SRCS)ft_drow_map\
		$(FOLDER_SRCS)ft_init_textures $(FOLDER_SRCS)ft_drow_3d\
		$(FOLDER_SRCS)ft_print $(FOLDER_SRCS)ft_drow_3d_utils\
		$(FOLDER_SRCS)ft_sprite_utils $(FOLDER_SRCS)ft_print_sprite\
		$(FOLDER_SRCS)ft_validate $(FOLDER_SRCS)ft_error_handler\
		$(FOLDER_SRCS)ft_validate_utils $(FOLDER_SRCS)ft_validate_utils_2\
		$(FOLDER_SRCS)ft_validate_utils_3 $(FOLDER_SRCS)ft_print_sprite_utils\
		$(FOLDER_SRCS)ft_key_press_utils

SRC = $(addsuffix .c, $(FUNC))
OBJ = $(addsuffix .o, $(FUNC))
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re norme

all: $(NAME)

$(NAME):
	@make -C ./minilibx_mms/
	@mv ./minilibx_mms/libmlx.dylib .
	@make -C ./libs/gnl
	@make -C ./libs/libft
	@make bonus -C ./libs/libft
	@mv ./libs/libft/libft.a .
	@mv ./libs/gnl/libgnl.a .
	@gcc -g -I $(HEADERS) $(SRC) libft.a libgnl.a -L. -lmlx \
        -framework OpenGL -framework AppKit -lm -o $(NAME)
	#gcc -I /usr/local/include $(SRC) ./libs/libft/libft.a ./libs/gnl/libgnl.a -L /USR/local/lib -lmlx -lXext -lX11 -lm -o $(NAME)

norme:
	@norminette $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all