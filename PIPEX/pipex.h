/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:23:46 by rgobet            #+#    #+#             */
/*   Updated: 2024/03/01 13:24:07 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "FT_PRINTF/ft_printf.h"
# include "FT_PRINTF/LIBFT/libft.h"

typedef struct s_vars{
	int		fd_parent;
	int		fd_child;
	int		fd[2];
	char	*path1;
	char	*path2;
	char	*file1;
	char	*file2;
	char	**cmd1;
	char	**cmd2;
	pid_t	pid;
}	t_vars;

void	init(t_vars *vars, int ac, char **av);
int		verification(char **av, t_vars *vars);
int		envp_path_verif(char **envp, char **av, t_vars *vars);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free(char **s);
void	free_vars(t_vars *vars);
void	error(t_vars *vars, char *s);
void	error_g(t_vars *vars, char **path);
void	verif_cmd(t_vars *vars, char **path, int opt);
char	**ft_split(char const *s, char c);
void	init_path(char **envp, t_vars *vars, int opt);
char	*ft_fill(char *s, char **path, t_vars *vars);
char	*ft_strjoin(char const *s1, char const *s2);
char	*path_verification(char **path, t_vars *vars, int opt);
char	*execution_right(char *cmd, char **path, t_vars *vars);

#endif
