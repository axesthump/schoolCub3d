/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:23:21 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 21:00:25 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H

#define CUB3D_H
#include "./libft.h"
#include "./get_next_line.h"
#include "../minilibx_mms/mlx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

#define	SPEED 0.1
#define ANGLE 66
#define VMOVE 128

typedef struct	s_win
{
	char 		**map;
	void		*mlx;
	void		*win;
	int			screen_w;
	int			screen_h;
	int			floor_color;
	int			ceilling_color;
}				t_win;

typedef struct	s_plr
{
	double		x;
	double		y;
	double		p_dir_x;
	double		p_dir_y;
	double		plane_x;
	double		plane_y;
}				t_plr;

typedef struct  s_data 
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct	s_raycast
{
	double 		camera_x;
	double 		ray_dir_x;
	double		ray_dir_y;
	double 		delta_dist_x;
	double		delta_dist_y;
	int 		mapX;
	int 		mapY;
	double		side_dist_x;
	double 		side_dist_y;
	double		perp_wall_dist;
	int 		stepX;
	int 		stepY;
	int 		hit;
	int 		side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		*buffer;
}				t_raycast;

typedef struct	s_textur_info
{
	char		*filename;
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int         bits_per_pixel;
    int         line_length;
    int         endian;

}				t_textur_info;

typedef	struct		s_texturs
{
	t_textur_info	so;
	t_textur_info	no;
	t_textur_info	we;
	t_textur_info	ea;
}					t_texturs;

typedef	struct	s_move
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			esc;
	int			l_arr;
	int			r_arr;
}				t_move;

typedef	struct	s_print
{
	int			color;
	int			y;
	double		shade;
	int			text_h;
	int			text_w;
	int			text_x;
	int			text_y;
	double		wall_x;
	double		step;
	double		tex_pos;
}				t_print;

typedef	struct		s_slist
{
	struct	s_slist	*next;
	double				x;
	double				y;
	double				dist;
}					t_slist;

typedef	struct		s_sprite
{
	t_slist			*el;
	t_textur_info	data;
	char			*filename;
}					t_sprite;

typedef	struct	s_validate
{
	int			r;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			s;
	int			f;
	int			c;
}				t_validate;

typedef	struct	s_s_print
{
	double		spr_x;
	double		spr_y;
	double		inv_det;
	double 		trnsfrm_x;
	double		trnsfrm_y;
	int			spr_scr_x;
	int			spr_h;
	int			start_y;
	int			end_y;
	int			spr_w;
	int			start_x;
	int			end_x;
	int			stripe;
	int			tex_x;
	int			y;
	int			d;
	int			color;
	int			tex_y;
}				t_s_print;

typedef	struct	s_v_map
{
	int			height;
	int			width;
}				t_v_map;

typedef struct	s_all
{
	t_win		window;
	t_plr		player;
	t_data		image;
	t_raycast	raycast;
	t_move		move;
	t_texturs	texturs;
	t_print		print;
	t_sprite	sprite;
	t_validate	validate;
	t_s_print	s_print;
	t_v_map		map_norme;	
	t_list		*list;
}				t_all;

void            ft_pixel_put(t_data *data, int x, int y, int color);
int				ft_get_map_and_player(t_all *all, int fd, t_list *list);
void			ft_key_press_handler(t_all *all);
int				ft_drow_map(t_all *all);
int				ft_init_textures(t_all *all);
void			ft_drow_3d(t_all *all);
void			ft_print(t_all *all, int line_height, int x_pix);
void			ft_r_init (t_raycast *r, t_all *all, int x_pix);
t_slist			*ft_sprite_new(double x, double y);
void			ft_sprite_clear(t_slist *sprite);
t_slist			*ft_sprite_last(t_slist *sprite);
void			ft_sprite_add_back(t_slist **lst, t_slist *new);
void			ft_print_sprite(t_all *all);
int				ft_get_pixel_color(t_textur_info *img, int x, int y);
int				ft_validate(t_all *all, t_list *list);
int	    		ft_error_handler(t_all *all, t_list *head, int err);
int				ft_check_nswe(t_all *all, char *row, int *change);
char			*ft_init_color(char *row, long *n);
int				ft_is_start_map(char *row);
int				ft_get_f(t_all *all, char *row);
int				ft_get_c(t_all *all, char *row);
int				ft_get_rgb(long *r, long *g, long *b, char *row);
int				ft_check_last_symbol(char *row, int is_num);
int				ft_get_we(t_all *all, char *row);
int				ft_get_ea(t_all *all, char *row);
int				ft_get_no(t_all *all, char *row);
int				ft_get_sprite_or_so(t_all *all, char *row);
int				ft_get_so_texture(t_all *all, char *row);
int				ft_get_sprite_texture(t_all *all, char *row);
int				ft_get_screen(t_all *all, char *row);
void			ft_get_screen_max_size(t_all *all);
void			ft_print_s_drow(t_all *all, t_s_print *s_prnt);
t_slist			*ft_sort_sprite(t_slist *head);
void			ft_move_w_s(t_all *all);
void			ft_move_a_d(t_all *all);
void			ft_turn_l_r(t_all *all);
int				ft_check_step(char **map, int y, int x);
int				ft_validate_map(t_all **all_m, char **map);
int				ft_make_screen(t_all *all);
void			ft_drow_sky_floor(t_all *all);
t_list			*ft_get_map(t_list *list);

# endif