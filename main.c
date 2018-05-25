/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:14:16 by agifford          #+#    #+#             */
/*   Updated: 2018/05/24 23:34:09 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main()
{
	t_tet	*tet;
	t_env	*env;

	tet = malloc(sizeof(*tet));
	env = init_env(tet);
	double_fuck(env);
	print_working_area(env);
	return (1);
}
