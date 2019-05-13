/*
** my_function.c for my_function.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
** 
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
** 
** Started on  Wed Feb  1 12:14:17 2017 Josselin
** Last update Wed Feb  8 00:42:28 2017 Josselin
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int     my_getnbr(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 0;
  if (str[0] == '-' && str[1] != '\0')
    i = i + 1;
  while (str[i] != '\0')
    {
      n = n + str[i] - 48;
      n = n * 10;
      i = i + 1;
    }
  n = n / 10;
  if (str[0] == '-')
    return (-1 * n);
  else
    return (n);
}

void	my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void	print_tab(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      my_putstr(str[i++]);
      write(1, "\n", 1);
    }
}
