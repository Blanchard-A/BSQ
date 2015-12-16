/*
** check.c for check in /home/blanch_p/test/BSQ
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Dec 16 13:38:19 2015 Alexandre Blanchard
** Last update Wed Dec 16 14:16:10 2015 Alexandre Blanchard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	check_bigger(char **tab, char **av, int nb_col)
{
  int	x;
  int	y;
  char	big;

  big = 0;
  x = 0;
  y = 0;
  while (tab[y] != NULL)
    {
      x = 0;
      while (x < nb_col)
        {
          if (tab[y][x] > big)
            big = tab[y][x];
          x++;
        }
      y++;
    }
  return (big);
}

int	check_i(char **tab, int mem, char **av, int nb_col)
{
  int	x;
  int	y;
  int	new_i;

  new_i = 0;
  x = 0;
  y = 0;
  while (tab[y] != NULL)
    {
      x = 0;
      while (x < nb_col)
        {
          if (tab[y][x] == mem)
            {
              new_i = x;
              return (new_i);
            }
          x++;
        }
      y++;
    }
}

int	check_j(char **tab, int mem, char **av, int nb_col)
{
  int	x;
  int	y;
  int	new_j;

  new_j = 0;
  x = 0;
  y = 0;
  while (tab[y] != NULL)
    {
      x = 0;
      while (x < nb_col)
        {
          if (tab[y][x] == mem)
            {
              new_j = y;
              return (new_j);
            }
          x++;
        }
      y++;
    }
}
