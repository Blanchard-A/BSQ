/*
** main.c for main in /home/blanch_p/test/BSQ
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Dec 16 11:08:35 2015 Alexandre Blanchard
** Last update Sat Dec 19 19:43:27 2015 Alexandre Blanchard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char	**malloc_tab(int nb_col, int nb_line)
{
  char	**tab;
  int	i;

  i = 0;
  tab = malloc(sizeof(char *) * nb_line);
  while (i < nb_line)
    {
      tab[i] = malloc(sizeof(char) * nb_col);
      i++;
    }
  return (tab);
}

int	make(int ac, char **av)
{
  int	nb_col;
  int	nb_line;
  char	**tab;
  int	mem;
  int	mem_i;
  int	mem_j;

  nb_col = nb_colonne(av[1], 0, 0);
  nb_line = nb_ligne(av[1]);
  tab = malloc_tab(nb_col, nb_line);
  all_in_tab(tab, nb_line, nb_col, av[1]);
  one_or_zero(tab);
  replace_number(tab, nb_col);
  mem = check_bigger(tab, av, nb_col);
  mem_i = check_i(tab, mem, av, nb_col);
  mem_j = check_j(tab, mem, av, nb_col);
  replace_square(tab, mem, mem_i, mem_j);
  replace_all(tab, av, nb_col, nb_line);
  show_double_tab(tab);
}

int	main(int ac, char **av)
{
  int	fd;

  if (ac == 1)
    {
      my_printf("Too few arguments\n");
      my_printf("Usage: ./bsq [PATH]\n");
    }
  else if (ac == 2)
    {
      if (fd = open(av[1], O_RDONLY) == -1)
	{
	  my_printf("No such file\n");
	  return (-1);
	}
      else
	make(ac, av);
    }
}
