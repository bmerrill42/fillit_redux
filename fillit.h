 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 19:00:11 by agifford          #+#    #+#             */
/*   Updated: 2018/05/23 15:04:58 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# define I {{'#','.','.','.'},{'#','.','.','.',},{'#','.','.','.'},X0
# define X0 {'#','.','.','.'}}
# define O {{'#','#','.','.'},{'#','#','.','.'},{'.','.','.','.'},X1
# define X1 {'.','.','.','.'}}
# define L {{'#','.','.','.'},{'#','.','.','.'},{'#','#','.','.'},X2
# define X2 {'.','.','.','.'}}
# define J {{'.','#','.','.'},{'.','#','.','.'},{'#','#','.','.'},X3
# define X3 {'.','.','.','.'}}
# define FLAT {{'#','#','#','#'},{'.','.','.','.'},{'.','.','.','.'},X4
# define X4 {'.','.','.','.'}}
# define L_180 {{'#','#','.','.'},{'.','#','.','.'},{'.','#','.','.'},X5
# define X5 {'.','.','.','.'}}
# define RIGHT_L {{'#','#','#','.'},{'#','.','.','.'},{'.','.','.','.'},X6
# define X6 {'.','.','.','.'}}
# define LEFT_L {{'.','.','#','.'},{'#','#','#','.'},{'.','.','.','.'},X7
# define X7 {'.','.','.','.'}}
# define J_180 {{'#','#','.','.'},{'#','.','.','.'},{'#','.','.','.'},X8
# define X8 {'.','.','.','.'}}
# define RIGHT_J {{'#','.','.','.'},{'#','#','#','.'},{'.','.','.','.'},X9
# define X9 {'.','.','.','.'}}
# define LEFT_J {{'#','#','#','.'},{'.','.','#','.'},{'.','.','.','.'},X10
# define X10 {'.','.','.','.'}}
# define LEFT_S {{'#','.','.','.'},{'#','#','.','.'},{'.','#','.','.'},X11
# define X11 {'.','.','.','.'}}
# define S {{'.','#','#','.'},{'#','#','.','.'},{'.','.','.','.'},X12
# define X12 {'.','.','.','.'}}
# define RIGHT_Z {{'.','#','.','.'},{'#','#','.','.'},{'#','.','.','.'},X13
# define X13 {'.','.','.','.'}}
# define Z {{'#','#','.','.'},{'.','#','#','.'},{'.','.','.','.'},X14
# define X14 {'.','.','.','.'}}
# define T_180 {{'.','#','.','.'},{'#','#','#','.'},{'.','.','.','.'},X15
# define X15 {'.','.','.','.'}}
# define LEFT_T {{'.','#','.','.'},{'#','#','.','.'},{'.','#','.','.'},X16
# define X16 {'.','.','.','.'}}
# define RIGHT_T {{'#','.','.','.'},{'#','#','.','.'},{'#','.','.','.'},X17
# define X17 {'.','.','.','.'}}
# define T {{'#','#','#','.'},{'.','#','.','.'},{'.','.','.','.'},X18
# define X18 {'.','.','.','.'}}
# define STACKARR {I, O, L, J, FLAT, L_180, RIGHT_L, LEFT_L, J_180, RIGHT_J,X19
# define X19 LEFT_J, LEFT_S, S, RIGHT_Z, Z, T_180, LEFT_T, RIGHT_T, T}
# define SUPERMAC	char	y[19][4][4] = STACKARRi
# define TET_X(c)	env->tet[c]->x
# define TET_Y(b)	env->tet[b]->y
# define TET(a)(b)(c)	env->tet[a]->tet[TET_Y(b)][TET_X(c)]

# define VOID2ARR(X) (*(char (*)[4][4])X)

typedef struct				s_global_list {
	void					*piecearr;
	struct s_global_list	*next;
	struct s_global_list	*prev;
}							t_arr_list;

typedef	struct			s_tet
{
	char				**tet;
	int					x;
	int					y;
}						t_tet;

typedef	struct			s_env
{
	char				**working_area;
	int					min_board;
	int					row;
	int					col;
	t_tet				*tets;
}						t_env;



static t_arr_list			*g_valid_pieces;

t_arr_list						*init_global();
void						print_piecearr(t_arr_list *node);
void						list_add(t_arr_list *head, void *data);
t_arr_list					*new_node(void *data);

#endif
