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
  int y_hash;
  int x_hash;
} t_tracker;

t_tracker *construct(char **read_piece) {
  t_tracker *ret;

  ret = (t_tracker*)ft_memalloc(sizeof(t_tracker));
  ret->candidate = read_piece;
  ret->top = get_top(read_piece);
  ret->left = get_left(read_piece);
  ret->y_hash = ret->top;
  ret->x_hash = ret->left;
  return (ret);
}

void next_hash(t_tracker *read_piece, int hash_count) {
  int x_offset = read_piece->left;
  int y_offset = read_piece->top;

  while (y_offset < 4){
    while (x_offset < 4){
      if (read_piece->candidate[y_offset][x_offset] == '#')
        hash_count--;
      if (!hash_count)
        break;
      x_offset++;
    }
    if (!hash_count)
      break;
    y_offset++;
    x_offset = read_piece->left;
  }
  read_piece->y_hash = y_offset;
  read_piece->x_hash = x_offset;
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


void remove_matches(t_tracker *read_piece, t_arr_list *rejects) {
  t_arr_list *traverse;
  
  traverse = g_valid_pieces->next;
  while(traverse != g_valid_pieces) {
    
    //remove all the unlike pieces
    if  (((char**)traverse->piecearr)               \
         [read_piece->y_hash - read_piece->top]     \
         [read_piece->x_hash - read_piece->left]    \
         !=                                         \
         read_piece->candidate                      \
         [read_piece->y_hash]                       \
         [read_piece->x_hash]){
      list_add(rejects, traverse);
      traverse->next->prev = traverse->prev;
      traverse->prev->next = traverse->next;
    }
    traverse = traverse->next;
  }
}

t_arr_list *validate(t_tracker *read_piece, t_arr_list *rejects, int hash_number) {
  if (g_valid_pieces->next == g_valid_pieces->prev)
    return (g_valid_pieces->next->piecearr == NULL \
            ? NULL                                 \
            : g_valid_pieces->next);
    next_hash(read_piece, hash_number);
    remove_matches(read_piece, rejects);
    hash_number++;
    return(validate(read_piece, rejects, hash_number));
}

//testing mains

<<<<<<< variant A
>>>>>>> variant B
//testing validation

int main() {
  char **ret;
  int x = 0;
  int y = 0;
  char arr[4][4] = {{'.','#','.','.'},                            \
                    {'.','#','#','.'},                            \
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

  if (hashes(ret) != 4)
    return(0);


  
  if (validate(construct(ret), rejects, 1) == NULL)
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
  
  printf("reconstructed\n");
    temp = g_valid_pieces->next;
  while (temp != g_valid_pieces) {
    print_piecearr(temp);
    printf("\n");
    temp = temp->next;
  }
  
}
======= end


//testing get top&&left

/* int main() { */
/*   char **ret; */
/*   int x; */
/*   int y; */
/*   char arr[4][4] = {{'.','#','#','.'},                                  \ */
/*                     {'#','#','.','.'},                                  \ */
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
