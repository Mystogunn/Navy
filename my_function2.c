/*
** my_function2.c for navy in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sun Feb  5 15:16:28 2017 Josselin
** Last update Fri Feb 17 19:02:10 2017 Josselin
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
      i++;
    }
  return (s1[i] - s2[i]);
}

int     my_put_nbr(int nb)
{
  int   modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb >= 0)
    {
      if ( nb > 9)
	{
	  modulo = nb % 10;
	  nb = (nb - modulo) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + modulo);
	}
      else
	{
	  my_putchar(nb + 48);
	}
    }
  return (nb);
}
