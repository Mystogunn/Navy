/*
** uncrypt.c for uncrypt.c in /home/josselin/EPITECH/NAVY
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sat Feb  4 16:21:25 2017 Josselin
** Last update Sun Feb 19 04:48:40 2017 Josselin
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char    *trad2(int i, int r, char *ret, char *str)
{
  int   j;

  while (str[i] != '0' && str[i] != 0)
    {
      j = 0;
      while (str[i] == '1')
	{
	  j++;
	  i++;
	}
      if (j > 0 && j <= 10)
	ret[r++] = (j - 1) + 48;
      else
	ret[r++] = (j + 6) + 48;
      i++;
    }
  ret[r] = 0;
  return (ret);
}

char    *trad(char *str)
{
  int   i;
  int   r;
  char  *ret;

  i = 0;
  r = 0;
  if ((ret = malloc(sizeof(char) * nbr_char(str) + 1)) == NULL)
    return (NULL);
  ret = trad2(i, r, ret, str);
  return (ret);
}
