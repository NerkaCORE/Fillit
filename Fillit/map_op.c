/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:24:38 by unli-yaw          #+#    #+#             */
/*   Updated: 2016/12/10 17:35:12 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft.h"


void	clean_map(char **map, char letter)
{
  int i;
  int j;

  i = 0;
  while (map[i])
  {
    j = 0;
    while (map[i][j])
    {
      if (map[i][j] == letter)
        map[i][j] = '.';
      j++;
    }
    i++;
  }
}

char **new_map(short len)
{
  short i;
  short j;
  char  **res;

  i = 0;
  res = (char**)malloc(sizeof(char*) * len + 1);
  if (!res)
      ft_putendl("malloc error in new map(1)\n");
  res[len] = NULL;
  while (len - i)
  {
    res[i] = (char*)malloc(sizeof(char) * len);
    if (!res[i])
      ft_putendl("malloc error in new map(2)\n");
    j = 0;
    while (len - j)
    {
        res[i][j] = '.';
        j++;
    }
    res[i][j] = '\0';
    i++;
  }
  return (res);
}

void	print_map(char **map)
{
  int i;
  int j;

  i = 0;
  while (map[i])
  {
    j = 0;
    while (map[i][j])
    {
      ft_putchar(map[i][j]);
      j++;
    }
    ft_putchar('\n');
    i++;
  }
}

char  **copy_map(char **map, short len)
{
  short i;
  short j;
  char  **res;

  i = 0;
  res = new_map(len + 1);
  while (len - i)
  {
    j = 0;
    while (len - j)
    {
      if (map[i][j] != '.')
        res[i][j] = map[i][j];
      j++;
    }
    res[i][j] = '\0';
    i++;
  }
  res[i] = NULL;
  return (res);
}
