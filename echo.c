
#include "shell.h"

void ft_flag(char **d, char *l)
{
  // char *l;
  // char **d;

  // l = t;
  // d = k;
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
}

void  ft_c(char **t)
{
  int b;
  int a;
  int i ;
  char *k;
  char *p;
  char *d[7]= {"\\t","\\a","\\r","\\v","\\b","\\n",NULL};
  char l[7] = {'\t','\a','\r','\v','\b','\n','\0'};

  p = *t;
  i = 0;
  while (i < 6)
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

void	ft_echo(char **av,char **environ,int ac)
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
  while (line[j])
  {
    if (line[j] == ';')
        i++;
    j++;
  }
  if (!(d = (char ***)malloc(sizeof(char **) * (i + 1))))
    return (0);
  t = ft_strsplit(t,';');
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