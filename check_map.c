/*
** check_map.c for navy in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sun Feb  5 12:03:02 2017 Josselin
** Last update Fri Feb 17 23:09:53 2017 Josselin
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

void	wrong_pos()
{
  my_putstr("wrong position\n");
  my_putstr("attack: ");
}

int	check_and_valid(char *pid)
{
  char	*str;

  str = catch_signal();
  usleep(10000);
  push_pid("011100", pid);
  if (my_strcmp("0100", str) != 0)
    return (-1);
  if (my_strcmp("01100", str) == 0)
    return (0);
  return (0);
}

char	**hit_or_miss(char *pid, char *pos, char **map_enemy)
{
  if (check_and_valid(pid) == -1)
    {
      my_putstr(pos);
      my_putstr(": missed\n");
      map_enemy = put_map(map_enemy, pos, 'o');
    }
  else
    {
      my_putstr(pos);
      my_putstr(": hit\n");
      map_enemy = put_map(map_enemy, pos, 'x');
    }
  return (map_enemy);
}

int	check_coord(char *str)
{
  if (str[0] < 49 || (str[0] > 56 && str[0] < 65) || (str[0] > 72
      && str[0] < 97) || str[0] > 104 || str[1] < 49
      || (str[1] > 56 && str[1] < 65) || (str[1] > 72 && str[1] < 97)
      || str[1] > 104)
    return (-1);
  if ((str[0] > 96 && str[0] < 105 && str[1] > 96 && str[1] < 105)
      || (str[0] > 64 && str[0] < 73 && str[1] > 64 && str[1] < 73)
      || (str[0] > 48 && str[0] < 57 && str[1] > 48 && str[1] < 57)
      || (str[0] > 96 && str[0] < 105 && str[1] > 64 && str[1] < 73)
      || (str[0] > 64 && str[0] < 73 && str[1] > 96 && str[1] < 105)
      || str[2] != 0)
    return (-1);
  return (0);
}

int	check_map(char **map, char *pos, char *pid)
{
  if (map[(pos[1] - 48) + 1][(pos[0] - 64) * 2] == '.'
      || map[(pos[1] - 48) + 1][(pos[0] - 64) * 2] == 'o')
    {
      push_pid("01100", pid);
      catch_signal();
      my_putstr(pos);
      my_putstr(": missed\n\n");
      return (-1);
    }
  else
    push_pid("0100", pid);
  catch_signal();
  my_putstr(pos);
  my_putstr(": hit\n\n");
  return (0);
}
