/*
** test.c for test in /home/blanch_p/rendu/Prog_elem/CPE_2015_BSQ
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Tue Dec  1 12:49:09 2015 Alexandre Blanchard
** Last update Wed Dec  9 16:12:31 2015 Alexandre Blanchard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

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

char	**malloc_tab(int nb_col, int nb_line)
{
  char	**tab;
  int	i;

  /* my_printf("col = %i\nline =%i\n", nb_col, nb_line); */
  i = 0;
  tab = malloc(sizeof(char *) * nb_line);
  while (i <= nb_col)
    {
      tab[i] = malloc(sizeof(char) * nb_col);
      i++;
    }
  return (tab);
}

int	show_double_tab(char **tab, int nb_line)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  /* my_printf("\n\n"); */
  /* my_printf("\n\n%s\n\n", tab[0]); */
  while (tab[j] != NULL)
    {
      my_printf("%s", tab[j]);
      j++;
    }
  /* my_printf("\n\n"); */
  return (0);
}

int	check_bigger(char **tab, char **av)
{
  int	x;
  int	y;
  int	big;
  int	nb_line;
  int	nb_col;

  nb_col = nb_colonne(av[1]);
  nb_line = nb_ligne(av[1]) / 2;
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

int	check_i(char **tab, int mem, char **av)
{
  int	x;
  int	y;
  int	new_i;
  int	nb_line;
  int	nb_col;

  nb_col = nb_colonne(av[1]);
  nb_line = nb_ligne(av[1]) / 2;
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

int	check_j(char **tab, int mem, char **av)
{
  int	x;
  int	y;
  int	new_j;
  int	nb_line;
  int	nb_col;

  nb_col = nb_colonne(av[1]);
  nb_line = nb_ligne(av[1]) / 2;
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

char	**replace_end(char **tab, int mem, int mem_i, int mem_j)
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

char	**replace_all(char **tab, char **av)
{
  int	x;
  int	y;
  int	big;
  int	nb_line;
  int	nb_col;

  nb_col = nb_colonne(av[1]);
  nb_line = nb_ligne(av[1]) / 2;
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

int	make(int ac, char **av)
{
  int nb_col;
  int nb_line;
  char **tab;
  int	j;
  int	mem;
  int	mem_i;
  int	mem_j;

  mem = 0;
  mem_i = 0;
  mem_j = 0;
  j = 0;
  nb_col = nb_colonne(av[1]);
  /* printf("nb_col ok\n"); */
  nb_line = nb_ligne(av[1]);
  /* printf("nb_line ok\n"); */
  tab = malloc_tab(nb_col, nb_line);
  /* printf("malloc ok\n"); */
  all_in_tab(tab, nb_line, nb_col, av[1]);
  /* printf("all_intab ok\n"); */
  one_or_zero(tab, nb_col, nb_line);
  /* printf("one zero ok\n"); */
  replace_number(tab, nb_col, nb_line);
  /* printf("replace number ok\n"); */
  mem = check_bigger(tab, av);
  /* printf("mem ok\n"); */
  mem_i = check_i(tab, mem, av);
  /* printf("mem_i ok\n"); */
  mem_j = check_j(tab, mem, av);
  /* printf("mem_j ok\n"); */
  replace_end(tab, mem, mem_i, mem_j);
  /* printf("end ok\n"); */
  replace_all(tab, av);
  /* printf("all ok\n"); */
  show_double_tab(tab, nb_line);

}

int	main(int ac, char **av)
{
  int	fd;

  if (ac == 1)
    {
      my_printf("Too few arguments\n");
      my_printf("Usage: ./bsq [PATH]\n");
      return (-1);
    }
  else if (ac == 2)
    {
      if (fd = open(av[1], O_RDONLY) == -1)
	{
	  my_printf("Bad file !\n");
	  return (-1);
	}
      else
	make(ac, av);
    }
}
