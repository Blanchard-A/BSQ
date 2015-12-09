/*
** test3.c for test3 in /home/blanch_p/rendu/Prog_elem/CPE_2015_BSQ
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Tue Dec  1 17:40:29 2015 Alexandre Blanchard
** Last update Wed Dec  9 16:13:09 2015 Alexandre Blanchard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char	**replace_number(char **tab, int nb_col, int nb_line)
{
  int	i;
  int	j;

  j = 1;
  i = 1;
  while (tab[j] != NULL)
    {
      if (tab[j][i] == '.')
        {
          tab[j][i] = check_minus(tab, i, j) + 1;
        }
      if (tab[j][i] == 'o')
	{

	  tab[j][i] = '0';
	}
      i++;
      if (i == nb_col)
        {

          j++;
          i = 0;
        }

    }
  return (tab);
}

char	**one_or_zero(char **tab, int nb_col, int nb_line)
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
  while (j < nb_line - 1)
    {
      if (tab[j][0] == '.')
        tab[j][0] = '1';
      else if (tab[j][0] == 'o')
        tab[j][0] = '0';
      j++;
    }
  return (tab);
}

char	**all_in_tab(char **tab, int nb_line, int nb_col, char *filepath)
{
  int	i;
  int	j;
  char	buffer[4096];
  int	k;

  k = 0;
  read(open(filepath, O_RDONLY), buffer, 4096);
  j = 0;
  i = 0;
  while (buffer[k] != '\n')
    k++;
  k = k + 1;
  /* my_printf("k = %i\n%c\nnb _col =%i\nnb _line =%i\n", k, buffer[k], nb_col, nb_line); */
  while (j < nb_line)
    {
      if (buffer[k] == '.' || buffer[k] == 'o')
	{
	  tab[j][i] = buffer[k];
	  /* my_printf("[%i][%i] = %c\n", j, i, buffer[k]); */
	  i = i + 1;
	  /* my_printf("ok"); */
	}
      else if (buffer[k] == '\n')
	{
	  tab[j][i] = buffer[k];
	  /* my_printf("[%i][%i]= %c\n", j, i, buffer[k]); */
	  /* my_printf("\n"); */
	  j = j + 1;
	  i = 0;
	}
      k = k + 1;
    }
  tab[j] = NULL;
  close (open(filepath, O_RDONLY));
  return (tab);
}
