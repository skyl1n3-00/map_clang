#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "map_lists.h"

//Function tests if the given linked list is empty returns 1 if true and 0 if not
int empty(map_int_int_ll *list) {
  if(list->null == 0)
    return 1;
  return 0;
}

//Function to print the linked list
void print(map_int_int_ll *list){
  map_int_int_ll *current = list;
  while(current != NULL){
    printf("[%d, %d]\n", current->val.key, current->val.value);
    current = current->next;
  }
}

//Function tests if two maps are equal return 1 if yes otherwise 0
int equals(map_int_int map1, map_int_int map2){
  if(map1.key != map2.key)
    return 0;
  if(map1.value != map2.value)
   return 0;
  
  return 1;
}

//Function to test if a given map element exists int the map
int exists(map_int_int_ll *list, map_int_int map){
  map_int_int_ll *current = list;
  while(current != NULL){
    if(equals(current->val, map)){
      return 1;
    }
    current = current->next;
  }
  return 0;
}


//Function tests if only the key is exists in a given list return 1 if yes otherwise 0
int key_exists(map_int_int_ll *list, int key){
  map_int_int_ll *current = list;
  while(current != NULL){
    if(current->val.key == key)
      return 1;
    current = current->next;
  }
  free(current);
  return 0;
}

//Function to insert the first element the list
int genesis_node(map_int_int_ll *list, map_int_int map){
  list->val = map;
  list->null = 1;
  return 1;
}

//Function to create a new map element and add it to a given list
int put_kv(map_int_int_ll *list, int key, int value){
  map_int_int_ll *current = list;
  map_int_int_ll *node = (map_int_int_ll*)malloc(sizeof(map_int_int_ll));
  //New map creation;
  map_int_int map = {key, value};
  if(empty(list)) {
    genesis_node(list, map);
  return 1;
  }
  if(key_exists(list, key)){
    while(current != NULL){
      if(current->val.key == map.key)
        current->val.value = map.value;
      current = current->next;
    }
  return 1;
  }
  node->val = map;
  node->next = NULL;
  while (1){
    if(current->next == NULL){
      current->next = node;
      break;
    }
    current = current->next;
  }
  return 1;
}

//Function to put a created map
int put_map(map_int_int_ll *list, map_int_int map){
  map_int_int_ll *current = list;
  if(empty(list)) {
    genesis_node(list, map);
  return 1;
  }
  if(key_exists(list, map.key)){
    while(current != NULL){
      if(current->val.key == map.key)
        current->val.value = map.value;
      current = current->next;
    }
  }
  put_kv(list, map.key, map.value);
  return 1;
}

//Function to get the size of the map
int map_size(map_int_int_ll *list){
  int i = 0;
  if(list == NULL)
    return 0;
  map_int_int_ll *current = list;
  while(current != NULL){
    i++;
    current = current->next;
  }
  return i;
}

//Function return the keyset of the given map
int* key_set(map_int_int_ll *list){
  map_int_int_ll *current = list;
  int i = 0;
  int *keys = calloc(map_size(list), sizeof(int));
  while( i < map_size(list) ){
    *(keys+i) = current->val.key;
    i++;
    current = current->next;
  }
  return keys;
}

//Function to return the value of a give key return -1 if the given key doesnt exists in the list
int get_value(map_int_int_ll *list, int key){
  if(!key_exists(list, key))
    return -1;
  map_int_int_ll *current = list;
  while(current != NULL){
    if(current->val.key == key){
      return current->val.value;
    }
    current = current->next;
  }
  free(current);
  return -1;
}

void put_dont_replace(map_int_int_ll *list, map_int_int map){
  if(key_exists(list, map.key))
    return;
  map_int_int_ll *current = list;
  put_map(list, map);
}

void put_dont_replace_kv(map_int_int_ll *list, int key, int value){
  map_int_int map;
  map.key = key;
  map.value = value;
  put_dont_replace(list, map);
}