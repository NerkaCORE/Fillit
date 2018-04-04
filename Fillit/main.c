/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:24:38 by unli-yaw          #+#    #+#             */
/*   Updated: 2016/12/10 17:35:12 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	usage(void)
{
	ft_putendl("usage: ./fillit target_file.\n");
}

void	ft_puterror(void)
{
	ft_putendl("error\n");
}

int		main(int ac, char **av)
{
	t_cfg	*cfg;

    cfg = NULL;
    if (!(cfg = (t_cfg*)malloc(sizeof(t_cfg))))
        return (0);
    if (ac == 2)
    {
        if ((cfg = open_file(av[1], cfg)) != NULL)
        {
            algo(cfg);
            print_map(cfg->map);
            return (1);
        }
        ft_puterror();
        return (0);
    }
    usage();
	return (0);
}
