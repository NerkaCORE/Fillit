/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:24:38 by unli-yaw          #+#    #+#             */
/*   Updated: 2016/12/10 17:35:12 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_point   *new_point(int x, int y)
{
  t_point *ret;

  if (!(ret = (t_point *)malloc(sizeof(t_point))))
    return (NULL);
  ret->x = x;
  ret->y = y;
  return (ret);
}

short     is_putable(char **map, t_point *start, t_tris *tris)
{
  short i;

  i = 0;
  while (4 - i)
  {
    if (!(map[start->y + (tris->coord[i].y)]) ||
        !(map[start->y + (tris->coord[i].y)][start->x + (tris->coord[i].x)]))
          return (0);
    if (((start->y + tris->coord[i].y >= 0) ||
        (start->x + tris->coord[i].x >= 0)) &&
        (map[start->y + (tris->coord[i].y)][start->x + (tris->coord[i].x)]
         != '.'))
          return (0);
    i++;
  }
  return (1);
}

void	    put_piece(char **map, t_point *start, t_tris *tris)
{
  short i;

  i = 0;
  while (4 - i)
  {
    map[start->y + tris->coord[i].y]
    [start->x + tris->coord[i].x] = tris->letter;
    i++;
  }
}

t_point   *give_next_point(t_point *start, char **map)
{
  t_point *ret;
  short   i;
  short   j;

  ret = new_point(-1, -1);
  i = start->y;
  j = start->x + 1;
  while (map[i])
  {
    while (map[i][j])
    {
      if (map[i][j] == '.')
      {
        ret->x = j;
        ret->y = i;
        return (ret);
      }
      j++;
    }
    j = 0;
    i++;
  }
  return (ret);
}
