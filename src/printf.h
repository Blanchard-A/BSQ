/*
** my.h for my in /home/blanch_p/test/printf/pointeurs
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Nov 11 15:36:28 2015 Alexandre Blanchard
** Last update Mon Nov 16 14:54:55 2015 Alexandre Blanchard
*/

#ifndef PRINTF_H_
#define PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int	p_hexa(va_list ap);
int	g_hexa(va_list ap);
int	octal(va_list ap);
int	bin(va_list ap);
int	fct_s(va_list ap);
int	entier(va_list ap);
int	unsign(va_list ap);
int	caract(va_list ap);
int	chain(va_list ap);
int	ptr(va_list ap);
int	pct(va_list ap);

#endif /* PRINTF_H_ */
