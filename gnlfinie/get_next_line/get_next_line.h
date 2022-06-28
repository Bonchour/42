/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:54:06 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/13 09:49:23 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char		*get_next_line(int fd);
int			ft_cpt(int cpt);
ssize_t		ft_mem(char *content, char *truecontent, int cpt, int fd);
int			ft_skip_line(int cpt, char *content);
void		ft_truereturn(int i, char *content, char *truecontent);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2, int k);
char		*ft_read(int fd);

#endif
