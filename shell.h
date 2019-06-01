/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:38:34 by yelazrak          #+#    #+#             */
/*   Updated: 2019/06/01 05:08:45 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

#include <fcntl.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include<signal.h> 
#include <unistd.h> 
#include <unistd.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <string.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
#include<stdio.h>
#define ANSI_COLOR_BLUE    "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"



typedef struct		s_lst
{
	char *str;
	struct  s_lst	*next;
}					t_lst;

char 	**ft_catpath(char **envp); 
char 	*ft_stat(char *path,char *p);
void	ft_read();
void	ft_cd(char *t);
int	ft_info(char *t);
char ***ft_separe(char *line);
void	ft_echo(char **av,char **environ);
void	ft_env(char **envp);
void ft_copy(char ***env,char **environ);
void	ft_setenv(char ***env,char *t);
void	ft_unsetenv(char ***env,char *t);
void	ft_execut(char **ar,char **line, char **envp);


#endif