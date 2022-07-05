/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:57:30 by amorel            #+#    #+#             */
/*   Updated: 2022/07/03 23:23:17 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <string.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define ARGS 1
# define PATH 2
# define BUFF 4

typedef struct s_data
{
	struct sigaction	sigact;
	char				**envp;
	char				**args;
	char				*buffer;
	char				*pathfile;
	int					used;
}t_data;

typedef struct s_utils
{
	int		dq;
	int		sq;
	int		first;
	char	*new_str;
	char	*tmp;
	char	*name;
	char	*new_name;
}t_utils;

typedef struct s_check
{
	int	dq;
	int	sq;
	int	last;
}t_check;

enum	e_char{espace, simpleq, doubleq, nothing};

char				**ft_split(char const *s, char c);
int					free_all(t_data *data);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_pwd(void);
void				ft_echo(char **args);
int					ft_quotes_is_odd(char *str);
void				ft_error(int errnb);
int					ft_quote_overlap(char *str);
void				ft_sig_handler(int sig, siginfo_t *siginfo, void *context);
void				set_ttys(void);
void				free_matrix(char **matrix);
void				ft_cd(char *str);
int					ft_env_exists(char **envp, char *str);
void				ft_env_change(t_data *data);
int					ft_matrix_len(char **envp);
char				*ft_getenv(char **envp, char *str);
char				**ft_copy_env(char **envp);
int					ft_env_check(char **envp, char *str);
void				ft_free(char **strmatrix, int j);
//init.c
struct sigaction	ft_init_sigset(void);
//check.c
int					ft_check_and_format(t_data *data);
void				ft_get_pathfile(t_data *data);
void				ft_get_pathfile_2(t_data *data, int i);
//export.c
void				ft_export(t_data *data);
//unset.c
void				ft_unset(t_data *data);
//env.c
void				ft_env(char **envp);
//env_utils.c
void				ft_fetch_env(t_data *data, size_t i);
void				ft_fetch_env_2(t_data *data, size_t i);
char				*ft_get_varname(char *str);
//exit.c
void				ft_exit(t_data *data);
//parsing.c
void				ft_parse(t_data *data);
//bazar de Hugo
void				ft_double_quote(t_utils *u);
void				ft_simple_quote(t_utils *u);
int					ft_join_env_utils(t_utils *u, int i, t_data *data);
int					ft_already_here(t_utils *u, int i, t_data *data);
void				ft_i_need_to_free(t_utils *u, t_data *data);
void				ft_parse_2(t_data *data);
void				ft_end_the_check(char **path, char *name, t_data *data);
int					ft_check_the_simple(int last, int sq);
int					ft_check_the_double(int last, int dq);
#endif
