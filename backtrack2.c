/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 23:06:22 by agifford          #+#    #+#             */
/*   Updated: 2018/05/23 15:00:11 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include "libft/libft.h"

int	min_area(char *str)
{
	int	num;
	int	ret;

	num = ((ft_strlen(str)) / 21) * 4;
	ret = 1;
	while (ret * ret < num)
		ret++;
	return (ret);
}

int	verify_spot(char *spot)
{
	int	count;

	count = 0;
	while (count < 21)
	{

	while (spot == '.') //modify 
		return (1);
	return (0);
}

int	figure_it(char *tets, int k, char *board)
{
	ft_memset(board, '.', 121);
	while (board[k] && !(verify_spot(board[i])))
	{
		verify_spot(tets);
		k++;
	}
	//here k comes out at the first available spot on the board (in the 1D string)
	put_piece(char *tets, int k, char *board);


int	put_piece(char **tets, int k, char **board)
{
	int	j;
	int	min_board;

	j = i - 21;
	min_board = min_area(tets);
	while (j < i && min_board < 12)
	{
		if (
}


int	main(argc, char **argv)
{
	char	**board;

	board = (char**)malloc(sizeof(char*) * 11);
	if (argc == 2)
		figure_it(
		return (0);
}

	

		

