/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:58:04 by agifford          #+#    #+#             */
/*   Updated: 2018/05/20 15:56:15 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

char	**double_array(char *s);

int	o_read(char **argv)
{
	int		fd;
	char	*sample;
	size_t	BUFF_SIZE;

	sample = NULL;
	BUFF_SIZE = 21;
	fd = open(argv[1], O_RDONLY);
	while (read(fd, sample, BUFF_SIZE) != 0)
	{
		double_array(sample);
		sample = sample + BUFF_SIZE;
	}
	return (0);
}

char	**double_array(char *s)
{
	char	**array;
	int x;
	int y;

	x = 0;
	y = 0;
	array = NULL;
	while (y < 4)
	{
		while (x < 5)
		{
			array[y][x]	= *s;
			s++;
			x++;
		}
		y++;
	}	
	write(1, "\n", 1);
	return (array);
}

int	main(int argc, char **argv)
{	
	if (argc == 2)	
		o_read(&argv[1]);
	return (0);
}
