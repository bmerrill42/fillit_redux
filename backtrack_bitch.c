/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_bitch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 23:06:22 by agifford          #+#    #+#             */
/*   Updated: 2018/05/24 23:28:16 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	can_put_piece(t_env *env) 
{
	TET_Y = 0;
	while (TET_Y < 4)
	{
		TET_X = 0;
		while (TET_X < 4)
		{
			if (TET == '#')
			{
				if (((TET_X + env->col > env->min_board) ||
						(TET_Y + env->row > env->min_board)) &&
						env->board[env->row + TET_Y][env->col + TET_X] != '.')
					return (0);
			}
			TET_X++;
		}
		TET_Y++;
	}
	return (1);
}	

void	put_piece(t_env *env) 
{
	TET_Y = 0;
	while (TET_Y < 4)
	{
		TET_X = 0;
		while (TET_X < 4)
		{
			if (TET == '#')
			{
				env->board[env->row + TET_Y][env->col + TET_X] =
					env->cur_tet + 'A';
			}
			TET_X++;
		}
		TET_Y++;
	}
}	

int	fuck_with_it(t_env	*env)
{
	env->row = 0;
	while (env->row < env->min_board)
	{
		env->col = 0;
		while (env->col < env->min_board)
		{
			if (env->board[env->row][env->col] == '.')
			{
				if (can_put_piece(env))
				{	
					put_piece(env);
					if (env->cur_tet < env->num_tets - 1)
					{
						env->cur_tet++;
						fuck_with_it(env);
					}
					else 
						return (1);
				}
			}
		}
	}
	return (0);
}

int	double_fuck(t_env *env)
{
	while (fuck_with_it(env) == 0)
	{
		if (env->min_board == 11)
			return (0);
		env->min_board++;
	}
	return (1);
}
