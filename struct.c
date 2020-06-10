#include<stdlib.h>
#include<stdio.h>

typedef struct{
  int key;
  int value;
}map;

typedef struct s_map_ll {
  map value;
  struct s_map_ll *next;
}map_ll;

int add_genesis_node(map_ll *ll, map genesis_node){
  ll->value = genesis_node;
  ll->next = NULL;
  return 1;
}

int add_node(map_ll *ll, map map){
  map_ll *current = ll;
  map_ll *node = (map_ll *)malloc(sizeof(map_ll));
  node->value = map;
  while (1) {
    if(current->next == NULL){
      current->next = node;
      break;
    }
    current = current->next;
  }
  return 1;
}

void print(map_ll *ll){
  map_ll *current = ll;
  while(current != NULL){
    printf("[%d, %d]\n", current->value.key, current->value.value);
    current = current->next;
  }
}

void main(){
  map map, second_map, third_map;
  map.key = 1;
  map.value = 2;
  map_ll *ll = (map_ll *)malloc(sizeof(map_ll));
  add_genesis_node(ll, map);
  second_map.key = 4;
  second_map.value = 6;
  third_map.key = 3;
  third_map.value = 18;
  add_node(ll, second_map);
  add_node(ll, third_map);
  add_node(ll, second_map);
  add_node(ll, third_map);
  print(ll);
  free(ll);
}
