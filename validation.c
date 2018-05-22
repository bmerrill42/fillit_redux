/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:39:50 by agifford          #+#    #+#             */
/*   Updated: 2018/05/18 17:30:43 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int next_hash(t_arr_list *traverse, t_tracker *read_piece, int hash_number) {
  int x_offset = read_piece->left;
  int y_offset = read_piece->top;

  while (y_offset < 4){
    while (x_offset < 4){
      if (read_piece->candidate[y_offset][x_offset] == '#') {
        hash_number--;
      }
      if (!hash_number)
        break;
        x_offset++;
    }
      if (!hash_number)
        break;
    y_offset++;
    x_offset = read_piece->left;
  }
    return (((char**)traverse->piecearr)[y_offset - read_piece->top][x_offset - read_piece->left] != read_piece->candidate[y_offset][x_offset]);
}

int hashes(char**piece) {
  int x = 0;
  int y = 0;
  int hashcount = 0;
  while (y < 4){
    while (x < 4){
      if (piece[y][x] == '#')
        hashcount++;
      x++;
    }
    y++;
    x = 0;
  }
  return hashcount;
}

t_arr_list *validate(t_tracker *read_piece, t_arr_list *rejects) {
  t_arr_list *traverse;
  int hash_number = 1;

  int loop = 0;
  
  
  traverse = g_valid_pieces->next;
  if (hashes(read_piece->candidate) != 4)
    return(NULL);
  while (g_valid_pieces->next != g_valid_pieces->prev){
    while(traverse != g_valid_pieces) {

      if  (next_hash(traverse, read_piece, hash_number)){
        list_add(rejects, traverse);
        traverse->next->prev = traverse->prev;
        traverse->prev->next = traverse->next;
      }
      traverse = traverse->next;
    }
    traverse = g_valid_pieces->next;
    hash_number++;


    printf("loop %d\n", loop++);
    
  }
  if (g_valid_pieces->next->piecearr == NULL)
    return (NULL);
  else
    return (g_valid_pieces->next);

}

//testing mains

//testing validation

int main() {
  char **ret;
  int x = 0;
  int y = 0;
  char arr[4][4] = {{'#','#','.','.'},                            \
                    {'.','.','.','#'},                            \
                    {'.','.','#','.'},                            \
                    {'.','.','.','.'}};
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

  t_arr_list *rejects = new_node(NULL);
	 
  g_valid_pieces = init_global();
  printf("candidates\n");

  x = 0;
  y = 0;
  if (validate(construct(ret), rejects) == NULL)
    {    printf("INVALID\n"); return 0;}
  temp = g_valid_pieces->next;
  while (temp != g_valid_pieces) {
    print_piecearr(temp);
    printf("\n");
    temp = temp->next;
  }

  temp = rejects->prev;
  while (temp != rejects) {
    ((t_arr_list*)temp->piecearr)->next->prev = ((t_arr_list*)temp->piecearr);
    ((t_arr_list*)temp->piecearr)->prev->next = ((t_arr_list*)temp->piecearr);
    temp = temp->prev;
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
