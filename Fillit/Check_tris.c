/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:24:38 by unli-yaw          #+#    #+#             */
/*   Updated: 2016/12/10 17:35:12 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_tris  *check_tris(t_tris *tris)
{
  t_point *coord;
  int     i;

  coord = tris->coord;
  i = 0;
  while (i < 4)
  {
    if (coord[i].x < 0 || coord[i].x > 4 || coord[i].y < 0 || coord[i].y > 4)
      return (0);
    i++;
  }
  if (check_tris_form(tris) == 0 || (tris = order_tris(tris)) == 0)
    return (NULL);
  return (tris);
}

char  check_tris_form(t_tris *tris)
{
  char    border;
  t_point *coord;
  int     i;
  int     j;

  i = 0;
  coord = tris->coord;
  border = 16;
  while (i < 4)
  {
    j = 0;
    while (j < 4)
    {
      if (((coord[i].x + 1 == coord[j].x && coord[i].y == coord[j].y) ||
          (coord[i].x - 1 == coord[j].x && coord[i].y == coord[j].y) ||
          (coord[i].x == coord[j].x && coord[i].y + 1 == coord[j].y) ||
          (coord[i].x == coord[j].x && coord[i].y - 1 == coord[j].y)) && i != j)
            border--;
      j++;
    }
    i++;
  }
  if (border <= 10)
    return (1);
  return (0);
}

t_tris  *order_tris(t_tris *tris)
{
  t_point *coord;
  int     i;
  int     x;
  int     y;

  coord = tris->coord;
  i = 0;
  x = coord[0].x;
  y = coord[0].y;
  while (i < 4)
  {
    coord[i].x = coord[i].x - x;
    coord[i].y = coord[i].y - y;
    i++;
  }
  return (tris);
}
