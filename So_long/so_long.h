/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:56:16 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/10 11:13:28 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map_error
{
	int		cpt;
	int		cpt2;
	int		ligne;
	int		ligne2;
	int		p;
	int		c;
	int		e;
	int		leftwall;
	char	save;
	char	*map;
}			t_map_error;

typedef struct s_matrice
{
	int	i;
	int	j;
	int	k;
}				t_matrice;

typedef struct s_fm
{
	int		fd;
	int		i;
	int		j;
	int		cpt;
	char	*buff;
}				t_fm;

typedef struct s_img
{
	char	*p;
	void	*i;
	int		x;
	int		y;
}			t_img;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_img		*f;
	t_img		*c;
	t_img		*g;
	t_img		*o;
	int			x;
	int			y;
	int			cptmoove;
	int			sprite;
	char		**map;
	t_map_error	*m;
}				t_vars;

void			ft_test_map(t_vars *v);
void			ft_test_map_4(t_vars *v, int fd);
void			ft_error_map(int e, int fd, t_vars *v);
t_map_error		*ft_init_map_error(t_map_error *m);
void			ft_init_image(t_vars *vars);
void			ft_wall(t_vars *vars, t_map_error *m);
void			ft_file_map(t_vars *v, t_map_error *m);
void			ft_file_0(int i, int j, t_vars *v);
void			ft_file_1(int i, int j, t_vars *v);
void			ft_file_e(int i, int j, t_vars *v);
void			ft_file_c(int i, int j, t_vars *v);
void			ft_file_p(int i, int j, t_vars *v);
void			ft_matrice(t_vars *vars, t_map_error *m);
void			ft_moove_up(t_vars *v);
void			ft_moove_down(t_vars *v);
void			ft_moove_left(t_vars *v);
void			ft_moove_right(t_vars *v);
void			ft_init_struc(t_vars *v, t_map_error *m, char *argv);
int				ft_mouse_hook(t_vars *v);
void			ft_free(t_vars *vars);
void			ft_free_map(char **map);
void			ft_free_image(t_vars *vars);
int				ft_animations(t_vars *vars);
void			ft_see_score(int nb, t_vars *v);
void			ft_init_image_2(t_img *o);
int				ft_anim_doggo_right(t_vars *v, int i, int doggo);
int				ft_anim_doggo_left(t_vars *v, int i, int doggo);
int				ft_where_dog(int i, t_vars *v);
void			ft_check_ber(char *str);
#endif
