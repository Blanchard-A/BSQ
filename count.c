/*
** count.c for count in /home/blanch_p/test/BSQ
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Dec 16 11:12:41 2015 Alexandre Blanchard
** Last update Wed Dec 16 14:16:38 2015 Alexandre Blanchard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	nb_ligne(char *file, int i, int y)
{
  char	buffer[4096];
  int	fd;

  fd = open(file, O_RDONLY);
  read(fd, buffer, 4096);
  while (buffer[i] != 0)
    {
      if (buffer[i] == '\n')
	y++;
      i++;
    }
  close(fd);
  return (y);
}

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

