/*
** change.c for change in /home/blanch_p/test/BSQ
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Dec 16 12:09:03 2015 Alexandre Blanchard
** Last update Wed Dec 16 14:15:30 2015 Alexandre Blanchard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char	**one_or_zero(char **tab)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tab[0][i] != '\n')
    {
      if (tab[0][i] == '.')
	tab[0][i] = '1';
      else if (tab[0][i] == 'o')
	tab[0][i] = '0';
      i++;
    }
  while (tab[j] != NULL)
    {
      if (tab[j][0] == '.')
	tab[j][0] = '1';
      else if (tab[j][0] == 'o')
	tab[j][0] = '0';
      j++;
    }
  return (tab);
}
