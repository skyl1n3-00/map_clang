#include<string.h>
#include<stdio.h>
#include "map_ii_functions.h"

void main(){
  map_int_int_ll *list = (map_int_int_ll*)malloc(sizeof(map_int_int_ll));
  int test = empty(list);
  printf("%d\n", test);
  genesis_node(list, 5, 2);
  put(list, 9, 1);
  put(list, 1, 2);
  put(list, 4, 1);
  test = empty(list);
  printf("%d\n", test);
  free(list);
}
