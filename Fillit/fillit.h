/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:17:33 by unli-yaw          #+#    #+#             */
/*   Updated: 2016/12/10 17:24:09 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct  s_point
{
    short       x;
    short       y;
}               t_point;

typedef struct  s_tris
{
    char        letter;
    t_point     coord[4];
}               t_tris;

typedef struct  s_cfg
{
    char          **map;
    short         min_size;
    char          nbr_piece;
    struct s_tris list_tris[26];
}               t_cfg;

t_cfg           *init_cfg(void);
t_cfg           *open_file(char *file, t_cfg *cfg);
t_cfg           *read_file(int *fd, t_cfg *cfg);
int             main(int ac, char **av);
t_tris          *create_tris(char *str, char name);
t_tris          *init_tris(char letter);
void	          create_tris_coord(t_tris *tris, int nbr, int i);
t_tris          *check_tris(t_tris *tris);
char            check_tris_form(t_tris *tris);
t_tris          *order_tris(t_tris *tris);
t_point         *new_point(int x, int y);
void	          algo(t_cfg *cfg);
int             verif(t_cfg *cfg, t_point *pos, char **map, int iter);
short           is_putable(char **map, t_point *start, t_tris *tris);
void	          put_piece(char **map, t_point *start, t_tris *tris);
t_point         *give_next_point(t_point *start, char **map);
void	          clean_map(char **map, char letter);
char            **new_map(short len);
void	          print_map(char **map);
char            **copy_map(char **map, short len);

#endif
