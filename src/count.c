/*
** count.c for count in /home/blanch_p/test/BSQ
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Dec 16 11:12:41 2015 Alexandre Blanchard
** Last update Sat Dec 19 19:42:23 2015 Alexandre Blanchard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	nb_colonne(char *file, int i, int y)
{
  char	buffer[4096];
  int	fd;

  fd = open(file, O_RDONLY);
  read(fd, buffer, 4096);
  while (buffer[i] != '\n')
    i++;
  i++;
  while (buffer[i] != '\n')
    {
      y++;
      i++;
    }
  y++;
  close(fd);
  return (y);
}

int	nb_ligne(char *file)
{
  char	buffer[4096];
  int	fd;
  char	*nb;
  int	i;
  int	find;

  i = 0;
  fd = open(file, O_RDONLY);
  read(fd, buffer, 4096);
  while (buffer[i] != '\n')
    {
      i++;
    }
  nb = malloc(sizeof(char) * i);
  i = 0;
  while (buffer[i] != '\n')
    {
      nb[i] = buffer[i];
      i++;
    }
  find = my_getnbr(nb) + 1;
  return (find);
}
