/*
** replace.c for replace in /home/blanch_p/test/BSQ
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Dec 16 12:21:31 2015 Alexandre Blanchard
** Last update Fri Dec 18 14:33:17 2015 Alexandre Blanchard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char	**replace_number(char **tab, int nb_col)
{
  int	i;
  int	j;

  i = 1;
  j = 1;
  while (tab[j] != NULL)
    {
      if (tab[j][i] == '.')
	tab[j][i] = check_minus(tab, i, j) + 1;
      if (tab[j][i] == 'o')
	tab[j][i] = '0';
      i++;
      if (i == nb_col)
	{
	  j++;
	  i = 1;
	}
    }
  return (tab);
}

int	check_minus(char **tab, int i, int j)
{
  int	minus;

  minus = tab[j - 1][i - 1];
  if (tab[j - 1][i] < minus)
    minus = tab[j - 1][i];
  if (tab[j][i - 1] < minus)
    minus = tab[j][i - 1];
  return (minus);
}

char	**replace_square(char **tab, int mem, int mem_i, int mem_j)
{
  int	i;
  int	j;

  i = mem_i - (mem - 49);
  j = mem_j - (mem - 49);
  while (j <= mem_j)
    {
      i = mem_i - (mem - 49);
      while (i <= mem_i)
        {
          tab[j][i] = 'x';
          i++;
        }
      j++;
    }
  return (tab);
}

char	**replace_all(char **tab, char **av, int nb_col, int nb_line)
{
  int	x;
  int	y;
  int	big;

  big = 0;
  x = 0;
  y = 0;
  while (tab[y] != NULL)
    {
      x = 0;
      while (x < nb_col - 1)
        {
          if (tab[y][x] == '0')
            tab[y][x] = 'o';
          else if (tab[y][x] != '0' && tab[y][x] != 'x')
            tab[y][x] = '.';
          x++;
        }
      y++;
    }
  return (tab);
}
