/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yassine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 04:36:48 by yelazrak          #+#    #+#             */
/*   Updated: 2019/06/01 04:50:40 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>


 
// int     voir_touche()
// {
//   char     buffer[3];
 
//   while (1)
//   {
//     read(0, buffer, 3);
//     if (buffer[0] == 27)
//       printf("C'est une fleche !\n");
//     else if (buffer[0] == 4)
//     {
//       printf("Ctlr+d, on quitte !\n");
//       return (0);
//     }
//   }
//   return (0);
// }

// int              main(int ac, char **av, char **env)
// {
//   char           *name_term;
//   struct termios term;
 
//   if ((name_term = getenv("TERM")) == NULL)
//      return (-1);
//   //tgetent(NULL, name_term);
//   term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
// term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
// term.c_cc[VMIN] = 1;
// term.c_cc[VTIME] = 0;
  
//   // remplis la structure termios des possibilités du terminal.
//   if (tcgetattr(0, &term) == -1)
//      return (-1);
//   voir_touche();
// return (0);
// }


int              main(int ac, char **av, char **env)
{
  char           *name_term;
  char *line;
  struct termios term;
 
  if ((name_term = getenv("TERM")) == NULL)
     return (-1);
  //tgetent(NULL, &name_term);
     //tgetent(NULL, name_term);
  term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
term.c_cc[VMIN] = 1;
term.c_cc[VTIME] = 0;
if (tcgetattr(0, &term) == -1)
     return (-1);
while (1)
{
	get_next_line(0,&line);
	ft_putendl(line);
}
  // remplis la structure termios des possibilités du terminal.
  
}
