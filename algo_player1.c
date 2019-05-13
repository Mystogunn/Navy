/*
** algo_player1.c for algo_player1.c in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Fri Feb  3 21:02:52 2017 Josselin
** Last update Sun Feb 19 23:26:29 2017 Josselin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "get_next_line.h"

int	crypt_and_push(char *str, char *pid)
{
  str = crypt_str(str);
  if (push_pid(str, pid) == -1)
    return (-1);
  return (0);
}

char	*tidy_coord(char *str)
{
  char	c;

  if (str[0] > 48 && str[0] < 57)
    {
      c = str[0];
      str[0] = str[1];
      str[1] = c;
    }
  if (str[0] > 96 && str[0] < 105)
    str[0] = str[0] - 32;
  return (str);
}

int	fight(char **map1, char **map_enemy2, char *pid)
{
  char	*pos;

  while (1)
    {
      my_putstr("attack: ");
      while (check_coord(pos = get_next_line(0)) == -1)
	wrong_pos();
      pos = tidy_coord(pos);
      crypt_and_push(pos, pid);
      map_enemy2 = hit_or_miss(pid, pos, map_enemy2);
      if (end_of_game2(map1, map_enemy2) == 0)
	break;
      my_putstr("\nwaiting for enemy’s attack...\n");
      pos = trad(catch_signal());
      if (check_map(map1, pos, pid) == -1)
	map1 = put_map(map1, pos, 'o');
      else
	map1 = put_map(map1, pos, 'x');
      if (end_of_game(map1, map_enemy2) == 1)
	return (1);
      all_print_map(map1, map_enemy2);
    }
  return (0);
}

char	**convert_tab(char *file)
{
  int	fd;
  char	**map;
  char	*str;
  int	i;

  i = 0;
  fd = open(file, O_RDONLY);
  if ((map = malloc(sizeof(char *) * 1000)) == NULL)
    return (NULL);
  while ((str = get_next_line(fd)) != NULL)
    {
      map[i] = str;
      i = i + 1;
    }
  map[i] = NULL;
  return (map);
}

int	algo_player1(char *filepath, char *str)
{
  char	**pos;
  char	**map_enemy2;
  char	**map1;

  pos = convert_tab(filepath);
  pos = convert_pos(pos);
  map_enemy2 = convert_tab("map.txt");
  map1 = convert_tab("map.txt");
  map1 = push_to_map(map1, pos);
  my_putstr("\nmy positions:\n");
  print_tab(map1);
  my_putstr("\nenemy's positions:\n");
  print_tab(map_enemy2);
  write(1, "\n", 1);
  if (fight(map1, map_enemy2, str) == 1)
    return (1);
  return (0);
}
