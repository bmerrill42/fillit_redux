/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:06:56 by agifford          #+#    #+#             */
/*   Updated: 2018/05/23 16:22:02 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include "libft/libft.h"


int	min_area(char *str)
{
	int num;
	int	ret;

	num = ((ft_strlen(str)) / 21) * 4;
	ret = 1;
	while (ret * ret < num)
		ret++;
	return (ret);
}

int	put_piece(char *tets, int i, char *board)
{
	int		j;
	int		min_board;

	j = i - 21
	min_board = min_area(tets);
	while (j < i && min_board < 12)
	{
		board[i] = tets[j++];
		if (j >= i && min_board < 12)
		{
			j = 0;
			i++;
			min_board++;
			if (min_board >= 12)
				return (NULL); // Invalidate solution proper error message
			put_piece(tets, i, board); 
		}
		if (min_board >= 12)
			return (0); 
		printf("%s", board);
		return (0);
	}
}	



int	main(int argc, char **argv)
{
	char	*board;

	board = (char*)malloc(sizeof(char) * 121);
	if (argc == 2)
		put_piece(argv[1], 0, board);
	return (0);
}





			

	



/*place piece on board
check to make sure its a valid spot on board (not interfering with other pieces)
take piece off the board*/

