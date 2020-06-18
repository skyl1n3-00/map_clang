#include<string.h>
#include<stdio.h>
#include "map_ii_functions.h"

void main(){
  map_int_int_ll *list = (map_int_int_ll*)malloc(sizeof(map_int_int_ll));
  put_kv(list, 9, 1);
  put_kv(list, 1, 2);
  put_kv(list, 4, 1);
  put_kv(list, 3, 1);
  put_dont_replace_kv(list, 9, 9);
  put_kv(list, 3, 3);
  print(list);
  int *keyset = key_set(list);
  int i;
  for(i = 0; i < map_size(list); i++){
    printf("%d\n", *(keyset+i));
  }
  printf("%d\n", get_value(list, 9));
  printf("%d\n", get_value(list, 11));
  free(list);
}
