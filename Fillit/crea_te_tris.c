/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_te_tris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:24:38 by unli-yaw          #+#    #+#             */
/*   Updated: 2016/12/10 17:35:12 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

//Initialise le tretrimino en lui donnant un nom et une coordonnée

t_tris  *init_tris(char letter)
{
  t_tris    *tris;
  t_point   *coord;
  int       i;

  i = 0;
  tris = NULL;
  if (!(tris = (t_tris *)malloc(sizeof(t_tris))))
    return (NULL);
  tris->letter = letter + 65;
  while (i < 4)
  {
    if (!(coord = (t_point*)malloc(sizeof(t_point))))
      return (NULL);
    coord->x = -1;
    coord->y = -1;
    tris->coord[i] = *coord;
    i++;
  }
  return (tris);
}

t_tris  *create_tris(char *str, char letter)
{
  t_tris  *tris;
  int     nbr;
  int     i;

  i = -1;
  nbr = 0;
  tris = init_tris(letter);
  while (++i < 20)
  {
    if (str[i] == '\n' && (i + 1) % 5 != 0)
      return (NULL);
    if (str[i] == '.' || str[i] == '\n')
      ;
    else if (nbr < 4 && str[i] == '#')
    {
      create_tris_coord(tris, nbr, i);
      nbr++;
    }
    else
      return (NULL);
  }
  // if (letter != 0 && str[i] == '\n')
  //   return (NULL);
  return (check_tris(tris));
}

void	create_tris_coord(t_tris *tris, int nbr, int i)
{
  t_point point;

  point = *new_point(i % 5, i / 5);
  tris->coord[nbr] = point;
}
