/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:24:38 by unli-yaw          #+#    #+#             */
/*   Updated: 2016/12/10 17:35:12 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

//Ouverture du fichier et verif des cas d'erreurs

t_cfg *open_file(char *file, t_cfg *cfg)
{
  int  fd;

  fd = open(file, O_DIRECTORY);
  if (fd >= 0)
   return (NULL);
  fd = open(file, O_RDONLY);
  if (fd < 0)
    return (NULL);
  if ((cfg = read_file(&fd, cfg)) == 0)
    return (NULL);
  return (cfg);
}

/*
**Read du fichier avec un buffsize de 21 (chaque tretrimino), puis on les
**place dans la stack
*/

t_cfg *read_file(int *fd, t_cfg *cfg)
{
  int     i;
  char    buff[21];
  int     cur_read;
  int     last_read;
  t_tris  *tris;

  i = 0;
  last_read = 0;
  while ((cur_read = read(*fd, buff, 21)))
  {
    last_read = cur_read;
    tris = create_tris(buff, i);
    if (!tris)
      return (NULL);
    cfg->nbr_piece = i + 1;
    cfg->list_tris[i] = *tris;
    i++;
  }
//  if (last_read != 20 || cur_read != 0)
//    return (NULL);
  return (cfg);
}
+