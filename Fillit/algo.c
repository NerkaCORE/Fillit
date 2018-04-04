/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:24:38 by unli-yaw          #+#    #+#             */
/*   Updated: 2016/12/10 17:35:12 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int   verif(t_cfg *cfg, t_point *pos, char **map, int iter)
{
  if (iter == cfg->nbr_piece)
    return (1);
  if (pos->x < 0)
    return (0);
  if (is_putable(map, pos, &cfg->list_tris[iter]))
  {
    put_piece(map, pos, &cfg->list_tris[iter]);
    if (verif(cfg, new_point(0, 0), map, iter + 1))
      return (1);
    clean_map(map, cfg->list_tris[iter].letter);
  }
  return (verif(cfg, give_next_point(pos, map), map, iter));
}

void	algo(t_cfg *cfg)
{
  char    **map;
  t_point *pos;

  pos = new_point(0, 0);
  cfg->min_size = 2;
  map = new_map(cfg->min_size);
  while (!(verif(cfg, pos, map, 0)))
  {
    cfg->min_size++;
    map = new_map(cfg->min_size);
  }
  cfg->map = copy_map(map, cfg->min_size);
}
