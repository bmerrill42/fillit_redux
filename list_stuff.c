#include "fillit.h"

t_arr_list *new_node(void *data) {
  t_arr_list *ret;
  ret = (t_arr_list*)calloc(1, sizeof(t_arr_list));
  ret->next = ret;
  ret->prev = ret;
  ret->piecearr = data;
  return (ret);
}

void list_add(t_arr_list *head, void *data) {
  t_arr_list *left;
  t_arr_list *insert;

  left = head->prev;
  insert = new_node(data);
  insert->prev = left;
  insert->next = head;
  left->next = insert;
  head->prev = insert;
}

void print_piecearr(t_arr_list *node) {
  if (!(unsigned int)node->piecearr)
    return;
  int i = 0;
  int j = 0;
  while (j < 4){
    i = 0;
    while (i < 4){
      printf("%c", ((char**)node->piecearr)[j][i]);
      i++;
    }
    j++;
    printf("\n");
  }
}

char **unstack_em(void *arr)
{
  char **ret;
  int x;
  int y;

  x = 0;
  y = 0;
  ret = (char**)ft_memalloc((sizeof(char*) * 4));
  while (y < 4)
    {
      ret[y] = (char*)ft_memalloc(sizeof(char) * 4);
      while (x < 4)
        {
          ret[y][x] = VOID2ARR(arr)[y][x];
          x++;
        }
      y++;
      x = 0;
    }
  return(ret);
}
void init_global() {
  STACKARR;
  g_valid_pieces = new_node(NULL);
  list_add(g_valid_pieces, unstack_em(&y0));
  list_add(g_valid_pieces, unstack_em(&y1));
  list_add(g_valid_pieces, unstack_em(&y2));
  list_add(g_valid_pieces, unstack_em(&y3));
  list_add(g_valid_pieces, unstack_em(&y4));
  list_add(g_valid_pieces, unstack_em(&y5));
  list_add(g_valid_pieces, unstack_em(&y6));
  list_add(g_valid_pieces, unstack_em(&y7));
  list_add(g_valid_pieces, unstack_em(&y8));
  list_add(g_valid_pieces, unstack_em(&y9));
  list_add(g_valid_pieces, unstack_em(&y10));
  list_add(g_valid_pieces, unstack_em(&y11));
  list_add(g_valid_pieces, unstack_em(&y12));
  list_add(g_valid_pieces, unstack_em(&y13));
  list_add(g_valid_pieces, unstack_em(&y14));
  list_add(g_valid_pieces, unstack_em(&y15));
  list_add(g_valid_pieces, unstack_em(&y16));
  list_add(g_valid_pieces, unstack_em(&y17));
  list_add(g_valid_pieces, unstack_em(&y18));
}

/*testing main please ignore*/
/* int main() { */
/*   t_arr_list *temp; */
/*   init_global(); */
/*   temp = g_valid_pieces->next; */
/*   while ((unsigned int)temp->piecearr) { */
/*     print_piecearr(temp); */
/*     printf("\n"); */
/*     temp = temp->next; */
/*   } */
/* } */
