#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "map_is_functions.h"

void main(){
  map_int_string_ll *list = (map_int_string_ll*)malloc(sizeof(map_int_string_ll));
  map_int_string map = {1, "Boob"}, map2 = {2, "Noah"}, map3 = {3, "Francis"};
  put_map(list, map);
  put_map(list, map2);
  map_int_string map4 = {1, "Jake"};
  put_map(list, map4);
  put_map(list, map3);
  put_kv(list, 5, "Monica");
  put_dont_replace_kv(list, 2, "Amine");
  print(list);
  free(list);
}
