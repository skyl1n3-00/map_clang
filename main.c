#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "map_ii_functions.h"

void main(){
  map_int_int_ll *list = (map_int_int_ll*)malloc(sizeof(map_int_int_ll));
  map_int_int map1 = {1, 1}, map2 = {2, 2}, map3 = {3, 3};
  int test = remove_at(list, 2);
  printf("%d\n", test);
  put_map(list, map1);
  put_map(list, map2);
  put_map(list, map3);
  print(list);
  test = remove_at(list, 0);
  printf("%d\n", test);
  print(list);
  free(list);
}
