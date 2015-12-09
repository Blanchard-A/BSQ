/*
** test2.c for test2 in /home/blanch_p/rendu/Prog_elem/CPE_2015_BSQ
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Tue Dec  1 15:36:10 2015 Alexandre Blanchard
** Last update Wed Dec  9 11:38:28 2015 Alexandre Blanchard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	nb_ligne(char *filepath)
{
  char	buffer[4096];
  int	i;
  int	fd;
  int	y;

  y = 0;
  i = 0;
  fd = open(filepath, O_RDONLY);
  read(fd, buffer, 4096);
  while (buffer[i] != '\n')
    i++;
  i++;
  while (buffer[i] != 0)
    {
      if (buffer[i] == '\n')
        y++;
      i++;
    }
  close(fd);
  /* printf("line = %i\n", y); */
  return (y);
}

int	nb_colonne(char *filepath)
{
  char	buffer[4096];
  int	i;
  int	fd;
  int	x;

  x =0;
  i = 0;
  fd = open(filepath, O_RDONLY);
  read(fd, buffer, 4096);
  while (buffer[i] != '\n')
    i++;
  i++;
  while (buffer[i] != '\n')
    {
      i++;
      x++;
    }
  x = x + 1;
  close(fd);
  /* printf("colonne = %i\n", x); */
  return (x);
}
