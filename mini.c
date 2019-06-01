/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:20:26 by yelazrak          #+#    #+#             */
/*   Updated: 2019/06/01 06:03:08 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

//extern char **environ;

 char *ft_stat(char *path,char *p)
{
    char *t;
	char *pp;

if (p[0] == '/')
	return (p);

    t = ft_strdup(path);
    pp = ft_strjoin(t,"/");
	free(t);
    t = ft_strjoin(pp,p);
	free(pp);
    return (t);
}
 char 	**ft_catpath(char **envp) 
{ 
    int i = 0;
	char **ar;
    char *t = NULL;

    while (envp[i])
    {
        if ((t = ft_strstr(envp[i],"PATH")))
            break;
        i++;
    }

    ar = ft_strsplit(ft_strchr(t,'=') + 1,':');
    return (ar);
}

void	ft_display(char ***str,char **environ,char **ar)
{
	int i;

	i = 0;
 		while (str[i])
		 {
			 	if (ft_info(str[i][0]) == 1)
					chdir(str[i][0]);
				else if (ft_strcmp(str[i][0],"setenv")==0)
				{
					ft_putendl(str[i][1]);
						ft_setenv(&environ,str[i][1]);
				}
				else if (ft_strcmp(str[i][0],"unsetenv")==0)
				{
						ft_putendl(str[i][1]);
						ft_unsetenv(&environ,str[i][1]);
				}
				else if (ft_strcmp(str[i][0],"env")==0)
					ft_env(environ);
				else if (ft_strcmp(str[i][0],"echo")==0)
					ft_echo(*(str + i),environ); 
				else if (ft_strcmp(str[i][0],"cd")==0)
					ft_cd(str[i][1]);	
				else if (ft_strcmp(str[i][0],"exit") == 0)
					{
						//ft_strfree(ar);
						exit(1);
					}
				else
				ft_execut(ar,*(str + i),environ);
				i++;
		 }
		 i = 0;

}

void	ft_read()
{
	char cwd[1024];
	char *t;

	getcwd(cwd,1024);
	ft_putstr( "["); 
 	ft_putstr(ANSI_COLOR_BLUE);
		if ((t = ft_strstr(cwd,"/Users/yelazrak")) != NULL)
			{
				ft_putstr("~");
		  		ft_putstr(t + 16);
			}
			else
		  		ft_putstr(cwd);
		 ft_putstr(ANSI_COLOR_RESET);
		ft_putstr( "]"); 
}



int main (int argc, char **argv, char **envp) 
{
	char *line;
	char **ar;
	char **environ;
	char ***str;
	int i;
	 char           *name_term;
  //char *line;
  struct termios term;
	
	(void)argc;
	(void)argv;
	i = 0;
	if ((name_term = getenv("TERM")) == NULL)
     return (-1);
  //tgetent(NULL, &name_term);
     //tgetent(NULL, name_term);
	if (tcgetattr(0, &term) == -1)
      return (-1);
  	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;

	 tcsetattr(0, TCSADRAIN, &term);
	ft_copy(&environ,envp);
	ar = ft_catpath(environ);
	
	while(1)
	{
		
		ft_read();
		 get_next_line(0,&line);
		 
		 if (!(str = ft_separe(line)))
			exit(1);	
	ft_display(str,environ,ar);
		free(line);
	}
}