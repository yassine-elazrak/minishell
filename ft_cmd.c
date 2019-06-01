/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:25:17 by yelazrak          #+#    #+#             */
/*   Updated: 2019/06/01 05:21:39 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern char **environ;

void	ft_env(char **envp)
{
	int i;

	i = 0;
	while(envp[i])
		ft_putendl(envp[i++]);
}

// t_lst *ft_alstnew(char *t)
// {
// 	t_lst *new;
// 	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
// 		return (NULL);
// 	new->str = ft_strdup(t);
// }

// void	ft_allocation(t_lst **tmp, char *t)
// {
// 	t_lst *lst;

// 	lst = *tmp;
// 	if (*tmp)
// 	{
// 		while (lst->next)
// 			lst = lst->next;
// 		lst->next = ft_alstnew(t);
// 	}
// 	else
// 	{
// 		*tmp = ft_alstnew(t);
// 	}
// }

void ft_copy(char ***env,char **environ)
{
	char **p;
	int i;

	i = 0;
	while(environ[i])
		i++;
	p = (char **)malloc(sizeof(char *)*(i + 1));
	i = -1;
	while(environ[++i])
		p[i] = ft_strdup(environ[i]);
	p[i] = NULL;
	*env = p;

}

void	ft_setenv(char ***env,char *t)
{
	char **p;
	char **environ;
	int i;

	i = 0;
	environ = *env;
	while(environ[i])
		i++;
	p = (char **)malloc(sizeof(char *)*(i + 2));
	i = -1;
	while(environ[++i])
		p[i] = ft_strdup(environ[i]);
	p[i++] = ft_strdup(t);
	p[i] = NULL;
	
	//ft_tabfree(*env);
	*env = p;
 	//ft_env(p);

}

void	ft_unsetenv(char ***env,char *t)
{

	char **environ;
	char **p;
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	k = 0;
	environ = *env;
	while(environ[++i])
	{
		if (ft_strcmp(environ[i],t) == 0)
			j = i;
	}
	p = (char **)malloc(sizeof(char *)*i);
	
	printf("i = %d j = %d\n",i,j);
	i = 0;
	while(environ[i])
	{
		if(i != j)
		{
			p[k] = ft_strdup(environ[i]);
			k++;
		}
		i++;
	}
	p[k] = NULL;
	//ft_tabfree(*env);
	env = &p;
}

void	ft_execut(char **ar,char **line, char **envp)
{
	pid_t pid;
	char *t;
	int i = 0;

	pid = fork();
	if (pid == -1)
	{
		perror(NULL);
		exit(1);
	}
	else if (pid == 0)
	{	
		while(ar[i]) 
		{
			t = ft_stat(ar[i],line[0]);
			if (execve(ft_stat(ar[i],line[0]),line,envp) != -1)
			{
					free(t);
					break;
			}
			free(t);
			i++;
		}
	}
	else
	{
		wait(NULL);
	}

}


void	ft_cd(char *t)
{
	char *p;

	if (ft_strcmp(t,"~") == 0)
	{
		p = ft_strdup("/Users/yelazrak");
	}
	else
	{
		p = ft_strdup(t);
	}
	if (chdir(p) == -1)
	{
		free(p);
		return ;
	}
	free(p);
		
}

void ft_flag(char ***k, char **t)
{
  char *l;
  char **d;

  if (!(d = (char **)malloc(sizeof(char *)* 7)))
    return ;
  if (!(l = ft_strnew(6)))
    return ;
  d[0] = ft_strdup("\\t");
  d[1] = ft_strdup("\\a");
  d[2] = ft_strdup("\\r");
  d[3] = ft_strdup("\\v");
  d[4] = ft_strdup("\\b");
  d[5] = ft_strdup("\\n");
  d[6] = NULL;
  l[0] = '\t';
  l[1] = '\a';
  l[2] = '\r';
  l[3] = '\v';
  l[4] = '\b';
  l[5] = '\n';
  l[6] = '\0';
	*k = d;
	*t = l;
}

void  ft_c(char **t)
{
  int b;
  int a;
  int i ;
  char *k;
  char *p;
  char **d = NULL;
  char *l = NULL;
  
  ft_flag(&d,&l);
  p = *t;
  i = 0;
  while (d[i])
  {
      a = ft_strlen(p);
      if((k = ft_strstr(p,d[i])))
      {
        b = ft_strlen(k);
         p[a - b] = l[i];
         ft_memmove(&p[a - b + 1],&p[a - b + 2] ,b);
         p[a- 1] = '\0';
      }
      i++;
  }
            ft_putstr(p);
}
 
void path(char *t,char **environ)
{
	int i;
	int l;
	char *p;

	i = 0;
	p  = NULL;
	p = ft_strrchr(t,'=');
	l = p - t;
	while (environ[i] )
	{
		if(ft_strncmp(environ[i],t,l) == 0)
			ft_putstr(environ[i + l]);
	}
	if (p)
		ft_putstr(p);
}

void	ft_verf(char *t)
{
	int j;

	j = ft_strlen(t);
	if (t[0] == '"' || t[0] == '\'' || t[j - 1] == '"' || t[j - 1] == '\'')
	{
		if (t[0] != t[j - 1])
		{
			ft_putstr("you are forgot to close");
			ft_putendl(" ");
			exit(1);
		}
		else
		  {
			ft_memmove(t,t + 1,j);
			t[j-2] = '\0';
		  }			
	}
}

void	ft_echo(char **av,char **environ)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (ft_strcmp(av[1],"-n") == 0)
	{
		i = 2;
		j = 1;
	}
	while(av[i])
	{
		ft_verf(av[i]);
		if(av[i][0] == '$')
			path(&av[i][0],environ);
		else
      ft_c(&av[i]);
    ft_putchar(' ');
		i++;
	}
	if (j == 0)
		ft_putchar('\n');
}

char ***ft_separe(char *line)
{
  char ***d;
  char **t;
  int i;
  int j;

  i = 0;
  j = 0;
if (ft_strstr(line,";;"))
	{
		ft_putendl("zsh: parse error near `;;'");
			return (NULL);
	}
  while (line[j])
  {
    if (line[j] == ';')
        i++;
    j++;
  }
  if (!(d = (char ***)malloc(sizeof(char **) * (i + 1))))
    return (0);
  t = ft_strsplit(line,';');
  i = 0;
  j = 0;
  while (t[i])
  {
      d[i] = ft_strsplit(t[i], ' ');
      i++;
  }
  d[i] = NULL;
  return (d);
}

int	ft_info(char *t)
{
	struct stat ss;
	t = ft_stat(".",t);

	if (0 > lstat(t,&ss) )
		return (-1);
	if 	(S_ISDIR(ss.st_mode))
		return (1);
	else
		return (-1);
	
}
