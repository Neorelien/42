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

void	test()
{
  printf("on sort pas ouai\n");
}
/*
   int main()
   {
   char *line;
   signal(SIGQUIT, test);
   while(1)
   {
   get_next_line(0, &line);
   printf("line = %s\n", line);
   }
   }
   */
int main(int argc, char **argv, char **env)
{
	char buffer[12];
	int fd[2];
	int forked;
	char test = EOF;
	char test2[4];
	test2[0] = 'l';
	test2[1] = 'o';
	test2[2] = 'l';
	pipe(fd);
	forked = fork();
	if (forked > 0)
	{
		close(fd[0]);
//		dup2(fd[1], 1);
//		close(fd[1]);
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
	
  return (0);
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
}
























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
