#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include "../minishell_utils.h"
#include <signal.h>
#include <curses.h>
#include <stdlib.h>
#include <term.h>
#include <ncurses.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
int main();
void	test()
{
  printf("on sort pas ouai\n");
}

char *ft_ctrlc(int nb, char *str)
{
	static int tocome;

	if (nb == 1 && tocome == 0)
		tocome = 1;
	else if (nb != 1 && tocome == 1)
	{
		tocome = 0;
		free(str);
		str = ft_strdup("");
	}
	return (str);
}

void	test2(int sign)
{
	lol(1, NULL);
}
   int main()
   {
	   int ret = 10;
	   char *linesave;
		   char *tmp;
		   char *term_type = getenv("TERM");
   char line[4];
struct termios s_termios;
        struct termios s_termios_backup;
   tgetent(NULL, term_type);
if (tcgetattr(0, &s_termios) == -1)
      return (-1);
if (tcgetattr(0, &s_termios_backup) == -1)
      return (-1);
s_termios.c_lflag &= ~(ICANON);
s_termios.c_lflag &= ~(ECHO);
tcsetattr(0, 0, &s_termios);
   signal(SIGQUIT, test);
   signal(SIGINT, test2);
linesave = ft_strdup("");
   while(ret)
   {	
	  line[0] = 0;
	line[1] = 0;
	line[2] = 0;
	line[3] = 0;
    	ret = read(0, &line, 3);
linesave = lol(0, linesave);
	if (*line == 10)
	{
	  	line[0] = 0;
		line[1] = 0;
		line[2] = 0;
		line[3] = 0;
		linesave = ft_strdup("");
	}
	if (*line == 4)
		break;	
	tmp = linesave;
	linesave = ft_strjoin(linesave, line);
	free(tmp);
   	printf("line = %s\n", linesave);
   }
   }
  
//int main(int argc, char **argv, char **env)
//{
//  while(1)
  //  ;
/*	char buffer[12];
	int fd[2];
	int forked;
	char test2[4];
	test2[0] = 'l';
	test2[1] = 'o';
	test2[2] = 'l';
	pipe(fd);
	write(fd[1], test2, 3);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	execve("/bin/cat", argv, env);*/
/*	forked = fork();
	if (forked > 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		write(fd[1], test2, 1);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		execve("/bin/cat", argv, env);
	}
*/	
  //return (0);
  /*
	 struct termios s_termios;
	 struct termios s_termios_backup;
	 int ret = 0;

	 (void)argc;
	 (void)argv;
	 char *term_type = getenv("TERM");

	 signal(SIGQUIT, test);
	 if (tgetent(NULL, term_type))// Fonction que vous aurez créé avec un tgetent dedans. 
	 {
	 if (tcgetattr(0, &s_termios) == -1)
	 return (-1);

	 if (tcgetattr(0, &s_termios_backup) == -1)
	 return (-1);

	 s_termios.c_lflag &= ~(ICANON); *//* Met le terminal en mode non canonique. La fonction read recevra les entrées clavier en direct sans attendre qu'on appuie sur Enter */
  //      s_termios.c_lflag &= ~(ECHO); /* Les touches tapées au clavier ne s'affficheront plus dans le terminal */
  /*

	 if (tcsetattr(0, 0, &s_termios) == -1)
	 return (-1);

	 char *BUF = NULL;

	 while (1)
	 {
	 BUF = malloc(2);
	 read(0, BUF, 2);
	 BUF[1] = 0;
	 printf("buf = %s|\n", BUF);

	 signal(SIGQUIT, test);
	 free(BUF);
	 BUF = NULL;
	 }

	 if (tcsetattr(0, 0, &s_termios_backup) == -1)
	 return (-1);
	 }

	 return ret;*/
//}
























/*
   t_sig g_sig;

   int	alrdy;

   void handler_next(int sign)
   {
   char 	*printed;
   int		len;

   ft_putstr_fd("\n", 0);
   if (g_sig.pid == -1)
   {
   printed = getenv("PWD");
   len = ft_strlen(printed);
   while (len >= 0 && printed[len] != '/')
   len--;
   printed += len + 1;
   ft_putstr_fd(printed, 0);
   ft_putstr_fd(" -> ", 0);
   }
   }

   void handler_quit(int sign)
   {
   ft_putstr_fd("\n\b\b\b\\b\b  \b\b", 0);
   }

   int ft_putchar(int c)
   {
   int lol = 1;
   write(0, &c, 1); 
   return (lol);
   }

   int ft_signal()
   {
   signal(SIGQUIT, handler_quit);
   while (42);
   return (1);
   }

   int main()
   {
   alrdy = 0;
   char *line;
   g_sig.pid = -1;
   g_sig.pid = fork();
   if (g_sig.pid == 0)
   {
   get_next_line(0, &line);
   printf("%s\n", line);
   free(line);
   }
   else
   {
   ft_signal();
   wait(NULL);
   }
   }*/
