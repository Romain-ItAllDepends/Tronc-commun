/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:56:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/02 21:47:22 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include "FT_PRINTF/ft_printf.h"
# include "FT_PRINTF/LIBFT/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "MLX42/include/MLX42/MLX42_Int.h"

typedef struct s_vars
{
	int		nb_collectable;
	int		nb_player;
	int		nb_exit;
	int		nb_move;
	int		x;	/* Horizontale */
	int		y;	/* Verticale */
	char	**map;
	mlx_texture_t	*player_left_t;
	mlx_image_t		*player_left_i;
	mlx_texture_t	*player_right_t;
	mlx_image_t		*player_right_i;
	mlx_texture_t	*player_down_t;
	mlx_image_t		*player_down_i;
	mlx_texture_t	*player_forward_t;
	mlx_image_t		*player_forward_i;
	mlx_texture_t	*grass_t;
	mlx_image_t		*grass_i;
	mlx_texture_t	*collectable_t;
	mlx_image_t		*collectable_i;
	mlx_texture_t	*wall_left_t;
	mlx_image_t		*wall_left_i;
	mlx_texture_t	*wall_right_t;
	mlx_image_t		*wall_right_i;
	mlx_texture_t	*wall_high_t;
	mlx_image_t		*wall_high_i;
	mlx_texture_t	*wall_down_t;
	mlx_image_t		*wall_down_i;
	mlx_texture_t	*corner_down_left_t;
	mlx_image_t		*corner_down_left_i;
	mlx_texture_t	*corner_down_right_t;
	mlx_image_t		*corner_down_right_i;
	mlx_texture_t	*corner_high_left_t;
	mlx_image_t		*corner_high_left_i;
	mlx_texture_t	*corner_high_right_t;
	mlx_image_t		*corner_high_right_i;
	mlx_texture_t	*exit_t;
	mlx_image_t		*exit_i;
}	t_vars;

int		ft_strlen_mod(char **s);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	init_map(char *path, t_vars *vars);
void	forbidden_char(t_vars *vars);
void	verification(t_vars *vars, int i, int j);
char	**ft_fill(t_vars *vars);
void	finishable(t_vars *vars);
void	finishable_verif(t_vars *vars, char **map);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free(char **s);

#endif
