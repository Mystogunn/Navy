/*
** get_next_line.h for get_next_line.h in /home/josselin/EPITECH/Get_next/bootstrap/include
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Fri Jan  6 05:29:11 2017 Josselin
** Last update Sun Feb 19 04:53:07 2017 Josselin
*/

#ifndef		MY_H_
# define	MY_H_

void	my_putstr(char *str);
int     first_player(char *filepath);
int     second_player(char **av);
char    *my_putnbr_bin(unsigned int nb);
int     my_getnbr(char *str);
char    *catch_signal();
int     algo_player1(char *filepath, char *str);
char    *crypt_str(char *str);
char    *trad(char *str);
int     nbr_char(char *str);
int     my_strlen(char *str);
char    **convert_pos(char **pos);
char    **push_to_map(char **map, char **pos);
int     algo_player2(char **av);
char    **convert_tab(char *file);
void    print_tab(char **str);
char    *convert_nbr(int i);
int     my_strlen(char *str);
int     check_coord(char *str);
int     my_strcmp(char *s1, char *s2);
int     push_pid(char *str, char *pid);
int     check_map(char **map, char *pos, char *pid);
int     check_and_valid(char *pid);
char    *get_next_line(const int fd);
char    **hit_or_miss(char *pid, char *pos, char **map_enemy);
char    **put_map(char **map, char *pos, char c);
char    *tidy_coord(char *str);
int     crypt_and_push(char *str, char *pid);
void    all_print_map(char **map, char **map_enemy);
void    wrong_pos();
int	end_of_game(char **map, char **map_enemy);
int	end_of_game2(char **map, char **map_enemy);
int     my_put_nbr(int nb);
int     coord_of_map(char **coord);
int	check_pos(char *pos);
char    **coord_of_map4(char **coord, int i);
int     coord_of_map5(char **map);

#endif /* !MY_H_ */
