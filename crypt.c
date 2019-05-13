/*
** crypt.c for crypt.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Thu Feb  2 20:16:06 2017 Josselin
** Last update Sun Feb 19 04:49:27 2017 Josselin
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	*fill_ret(char *ret, int a, int c)
{
  while (c > 0)
    {
      ret[a] = '1';
      a++;
      c--;
    }
  ret[a] = '0';
  return (ret);
}

char	*check_car(char *str, char *ret, int i, int a)
{
  int	c;

  while (str[i] != 0)
    {
      if (str[i] >= 'A' && str[i] <= 'H')
  	{
  	  c = str[i++] - 6 - '0';
  	  ret = fill_ret(ret, a, c);
  	  fill_ret(ret, a, c);
  	  a = a + c + 1;
  	}
      else if (str[i] >= '0' && str[i] <= '9')
  	{
  	  c = str[i++] - '0' + 1;
  	  ret = fill_ret(ret, a, c);
  	  fill_ret(ret, a, c);
  	  a = a + c + 1;
  	}
    }
  ret[a] = '0';
  ret[a + 1] = 0;
  return (ret);
}

char	*crypt_str(char *str)
{
  int	i;
  int	a;
  char	*ret;

  i = 0;
  a = 0;
  if ((ret = malloc(sizeof(char) * my_strlen(str) * 18)) == NULL)
    return (NULL);
  ret = check_car(str, ret, i, a);
  return (ret);
}

int	nbr_char(char *str)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (str[i])
    {
      if (str[i] == '0')
	a++;
      i++;
    }
  return (a);
}
