# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/07 16:12:25 by casubmar          #+#    #+#              #
#    Updated: 2020/09/09 19:30:17 by casubmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEADERS = /include
FOLDER_SRCS = ./srcs/
FUNC =	cub3d ft_pixel_put ft_get_map_and_player ft_key_press ft_drow_map\
		ft_init_textures ft_drow_3d ft_print ft_drow_3d_utils\
		ft_sprite_utils ft_print_sprite ft_validate ft_error_handler\
		ft_validate_utils ft_validate_utils_2 ft_validate_utils_3\
		ft_print_sprite_utils ft_key_press_utils ft_validate_map\
		ft_make_screen ft_get_map_and_player_utils get_next_line\
		get_next_line_utils cub3d_utils cub3d_utils_2 cub3d_utils_3\
		cub3d_utils_4


SRC = $(addprefix $(FOLDER_SRCS), $(addsuffix .c, $(FUNC)))
OBJ = $(addprefix $(FOLDER_SRCS), $(addsuffix .o, $(FUNC)))
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re norme

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./minilibx_mms/
	@mv ./minilibx_mms/libmlx.dylib .
	@gcc -g -I $(HEADERS) $(OBJ) -L. -lmlx \
        -framework OpenGL -framework AppKit -lm -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

norme:
	@norminette $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all