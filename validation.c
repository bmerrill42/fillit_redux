#include "fillit.h"

int get_top(char **piece) {
  int x = 0;
  int y = 0;
  while (y < 4) {
    x = 0;
    while (x < 4 && piece[y][x] != '#') {
      if (piece[y][x] == '#')
        break;
      x++;
    }
    if (piece[y][x] == '#')
      break;
    y++;
  }
  return(y);
}

int get_left(char **piece) {
  int y = 0;
  int x = 0;
  while (x < 4) {
    y = 0;
    while (y < 4 && piece[y][x] != '#') {
      if (piece[y][x] == '#')
        break;
      y++;
    }
    if (y < 4 && piece[y][x] == '#')
      break;
    x++;
  }
  return(x);
}

typedef struct s_tracker {
	char** candidate;
	int top;
	int left;
} t_tracker;

t_tracker *construct(char **read_piece) {
    t_tracker *ret;

	ret = (t_tracker*)ft_memalloc(sizeof(t_tracker));
	ret->candidate = read_piece;
	ret->top = get_top(read_piece);
	ret->left = get_left(read_piece);
	return (ret);
}

t_arr_list *validate(t_tracker *read_piece, int x_offset, int y_offset) {
	t_arr_list *traverse;
	t_arr_list *rejects;

	rejects = new_node(NULL);
	traverse = g_valid_pieces->next;
	while(traverse != g_valid_pieces) {

		if (((char**)traverse->piecearr)[y_offset][x_offset] != read_piece->candidate[read_piece->top + y_offset][read_piece->left + x_offset]) {
			list_add(rejects, traverse);
			traverse->next->prev = traverse->prev;
			traverse->prev->next = traverse->next;
		}
		traverse = traverse->next;
	}
	if (g_valid_pieces->next == g_valid_pieces->prev && g_valid_pieces != g_valid_pieces->prev)
		return (g_valid_pieces->next);
	else
		return (NULL);
}

//testing mains

//testing validation

int main() {
	char **ret;
	int x = 0;
	int y = 0;
	char arr[4][4] = {{'.','.','.','.'},                                  \
					  {'.','.','.','.'},                                  \
					  {'.','.','#','#'},                                  \
					  {'.','#','#','.'}};
	 t_arr_list *temp;

	   x = 0;
  y = 0;
  ret = (char**)ft_memalloc((sizeof(char*) * 4));
  while (y < 4)
    {
      ret[y] = (char*)ft_memalloc(sizeof(char) * 4);
      while (x < 4)
        {
          ret[y][x] = arr[y][x];
          x++;
        }
      y++;
      x = 0;
    }


	 
	 init_global();
	 temp = g_valid_pieces->next;
	 while ((unsigned int)temp->piecearr) {
	   print_piecearr(temp);
	   printf("\n");
	   temp = temp->next;
	 }

	
	validate(construct(ret), x, y);
	 temp = g_valid_pieces->next;
	 while (temp != g_valid_pieces) {
	   print_piecearr(temp);
	   printf("\n");
	   temp = temp->next;
	 }
	 
}


//testing get top&&left

/* int main() { */
/*   char **ret; */
/*   int x; */
/*   int y; */
/*   char arr[4][4] = {{'.','.','.','.'},                                  \ */
/*                     {'.','.','.','.'},                                  \ */
/*                     {'.','.','#','#'},                                  \ */
/*                     {'.','#','#','.'}}; */
/*   t_arr_list test; */

/*   x = 0; */
/*   y = 0; */
/*   ret = (char**)ft_memalloc((sizeof(char*) * 4)); */
/*   while (y < 4) */
/*     { */
/*       ret[y] = (char*)ft_memalloc(sizeof(char) * 4); */
/*       while (x < 4) */
/*         { */
/*           ret[y][x] = arr[y][x]; */
/*           x++; */
/*         } */
/*       y++; */
/*       x = 0; */
/*     } */
/*   test.piecearr = ret; */
/*   print_piecearr(&test); */
/*   printf("%d %d\n", get_top(ret), get_left(ret)); */
/* } */
