/*
** algo_player2.c for navy in /home/josselin/EPITECH/NAVY/PSU_2016_navy
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sun Feb  5 02:28:31 2017 Josselin
** Last update Fri Feb 17 20:35:22 2017 Josselin
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

void	all_print_map(char **map, char **map_enemy)
{
  my_putstr("my positions:\n");
  print_tab(map);
  my_putstr("\nenemy's positions:\n");
  print_tab(map_enemy);
  my_putstr("\n");
}

char	**put_map(char **map, char *pos, char c)
{
  map[pos[1] - 47][(pos[0] - 64) * 2] = c;
  return (map);
}

char    *trad_and_catch()
{
  char	*str;

  str = catch_signal();
  str = trad(str);
  return (str);
}

int	fight2(char **map2, char **map_enemy1, char *pid)
{
  char	*pos;

  while (1)
  {
    my_putstr("waiting for enemy’s attack...\n");
    pos = trad(catch_signal());
    if (check_map(map2, pos, pid) == -1)
      map2 = put_map(map2, pos, 'o');
    else
      map2 = put_map(map2, pos, 'x');
    if (end_of_game(map2, map_enemy1) == 1)
      return (1);
    my_putstr("attack: ");
    while (check_coord(pos = get_next_line(0)) == -1)
      wrong_pos();
    pos = tidy_coord(pos);
    crypt_and_push(pos, pid);
    map_enemy1 = hit_or_miss(pid, pos, map_enemy1);
    if (end_of_game2(map2, map_enemy1) == 0)
      break;
    my_putstr("\n");
    all_print_map(map2, map_enemy1);
  }
  return (0);
}

int	algo_player2(char **av)
{
  char	**pos2;
  char	**map_enemy1;
  char	**map2;

  pos2 = convert_tab(av[2]);
  pos2 = convert_pos(pos2);
  map_enemy1 = convert_tab("map.txt");
  map2 = convert_tab("map.txt");
  map2 = push_to_map(map2, pos2);
  my_putstr("\nmy positions:\n");
  print_tab(map2);
  my_putstr("\nenemy's positions:\n");
  print_tab(map_enemy1);
  write(1, "\n", 1);
  if (fight2(map2, map_enemy1, av[1]) == 1)
    return (1);
  return (0);
}
