/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:56:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/23 14:31:04 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "FT_PRINTF/ft_printf.h"
# include "FT_PRINTF/LIBFT/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "MLX42/include/MLX42/MLX42_Int.h"

typedef struct s_vars
{
	mlx_texture_t		*player_left_t;
	mlx_texture_t		*player_right_t;
	mlx_texture_t		*player_down_t;
	mlx_texture_t		*player_forward_t;
	mlx_texture_t		*grass_t;
	mlx_texture_t		*collectable_t;
	mlx_texture_t		*wall_left_t;
	mlx_texture_t		*wall_right_t;
	mlx_texture_t		*wall_high_t;
	mlx_texture_t		*wall_down_t;
	mlx_texture_t		*corner_down_left_t;
	mlx_texture_t		*corner_down_right_t;
	mlx_texture_t		*corner_high_left_t;
	mlx_texture_t		*corner_high_right_t;
	mlx_texture_t		*exit_t;
	mlx_texture_t		*bush_t;
	mlx_image_t			*player_left_i;
	mlx_image_t			*player_right_i;
	mlx_image_t			*player_down_i;
	mlx_image_t			*player_forward_i;
	mlx_image_t			*grass_i;
	mlx_image_t			*collectable_i;
	mlx_image_t			*wall_left_i;
	mlx_image_t			*wall_right_i;
	mlx_image_t			*wall_high_i;
	mlx_image_t			*wall_down_i;
	mlx_image_t			*corner_down_left_i;
	mlx_image_t			*corner_down_right_i;
	mlx_image_t			*corner_high_left_i;
	mlx_image_t			*corner_high_right_i;
	mlx_image_t			*exit_i;
	mlx_image_t			*bush_i;
	mlx_t				*mlx;
	char				**map;
	int					nb_collectable;
	int					nb_player;
	int					nb_exit;
	int					nb_move;
	int					i;
	int					j;
}	t_vars;

int		ft_strlen_mod(char **s);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	init_map(char *path, t_vars *vars);
void	no_void(t_vars *vars, char *map);
void	forbidden_char(t_vars *vars);
void	verification(t_vars *vars, int i, int j);
char	**ft_fill(t_vars *vars);
void	finishable(t_vars *vars);
char	**security_finishable(char **map);
void	finishable_verif(t_vars *vars, char **map);
void	parse_map(t_vars *vars, mlx_t *mlx);
void	init_img(t_vars *vars);
void	corner_print(t_vars *vars, mlx_t *mlx, int length_v, int length);
void	wall_print(t_vars *vars, int length_v, int i, int j);
void	other_print(t_vars *vars, mlx_t	*mlx, int i, int j);
void	grass_and_bush_print(t_vars *vars, int length_v, int i, int j);
void	move(t_vars *vars, mlx_t *mlx);
void	reprint_collectable(t_vars *vars);
void	right(t_vars *vars);
void	left(t_vars *vars);
void	up(t_vars *vars);
void	down(t_vars *vars);
void	escape(t_vars *vars);
void	*ft_calloc(size_t nmemb, size_t size);
void	textures_verif(t_vars *vars);
void	free_textures(t_vars *vars);
void	free_textures_s(t_vars *vars);
void	free_images(t_vars *vars);
void	ft_free(char **s);
void	ft_error_one(t_vars *vars);
void	ft_error_two(t_vars *vars, char **tab);
void	ft_error_three(t_vars *vars);
void	ft_error_four(t_vars *vars);
void	ft_win(t_vars *vars);

#endif
