/*
** tab.c for tab in /home/blanch_p/test/BSQ
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Dec 16 11:43:49 2015 Alexandre Blanchard
** Last update Wed Dec 16 14:30:53 2015 Alexandre Blanchard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char	**all_in_tab(char **tab, int nb_line, int nb_col, char *file)
{
  int	i;
  int	j;
  char	buffer[4096];
  int	k;

  read(open(file, O_RDONLY), buffer, 4096);
  i = 0;
  j = 0;
  k = jump(buffer);
  while (j < nb_line)
    {
      if (buffer[k] == '.' || buffer[k] == 'o')
	tab[j][i] = buffer[k];
      else
	{
	  tab[j][i] = buffer[k];
	  j++;
	  i = -1;
	}
      i++;
      k++;
    }
  tab[j] = NULL;
  close (open(file, O_RDONLY));
  return (tab);
}

int	show_double_tab(char **tab)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tab[j + 1] != NULL)
    {
      my_printf("%s", tab[j]);
      j++;
    }
  return (0);
}

int	jump(char *buffer)
{
  int	k;

  k = 0;
  while (buffer[k] != '\n')
    k++;
  k++;
  return (k);
}
