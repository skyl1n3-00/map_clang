#include<stdlib.h>
#include<stdio.h>
#include "map_lists.h"

/*
int empty(list)
void print(list)
int equals(map1, map2)
int exists(list, map)
int exists_key(list, key)
int put_kv(list, key, value)
int put_map(list, map)
int map_size(list)
int* key_set(list)
int get_value(key)
int put_dont_replace_map(list, map)
int put_dont_replace_kv(list, key, value)
*/

//Function tests if the given linked list is empty returns 1 if true and 0 if not
int empty(map_int_int_ll *list) {
  if(list->null == 0)
    return 1;
  return 0;
}

//Function to print map
void print(map_int_int_ll *list){
  map_int_int_ll *current = list;
  while(current != NULL) {
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
    if(equals(current->val, map))
      return 1;
    current = current->next;
  }
  return 0;
}

/*Function tests if only the key is exists in a given list 
return 1 if yes otherwise 0 */
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

//Function to insert the first element in the map struct
int genesis_node(map_int_int_ll *list, map_int_int map){
  if(list->null == 1)
    return 0;
  list->val = map;
  list->null = 1;
  return 1;
}

//Function to insert a map element int the given map struct
int put_kv(map_int_int_ll *list, int key, int value){
  map_int_int_ll *current = list;
  map_int_int map = {key, value};
  
  //We check if the list is empty, if it's the case we insert the first element
  if(empty(list)){
    genesis_node(list, map);
    return 1;
  }

  //We check if the key already exists in the list we override the old value
  if(key_exists(list, key)){
    while(current != NULL){
      if(current->val.key == map.key){
        current->val.value = map.value;
        break;
      }
      current = current->next;
    }
    return 1;
  }

  //We create a new node and then insert it in the list
  map_int_int_ll *node = (map_int_int_ll *)malloc(sizeof(map_int_int_ll));
  node->val = map;
  node->next = NULL;
  while (current != NULL){
    if(current->next == NULL){
      current->next = node;
      break;
    }
    current = current->next;
  }
  return 1;
}

//Function to insert created map element to a given map struct
int put_map(map_int_int_ll *list, map_int_int map){
  int operation_state = put_kv(list, map.key, map.value);
  return operation_state;
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
  int *keys = (int* )calloc(map_size(list), sizeof(int));
  while( i < map_size(list) ){
    *(keys+i) = current->val.key;
    i++;
    current = current->next;
  }
  return keys;
}

/*Function to return the value of a give key return -1 if the given key 
doesnt exists in the list */
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

/*Function to insert a map node into the struct but doesnt replace if 
the actual map is already exists in the struct(map)*/
int put_dont_replace(map_int_int_ll *list, map_int_int map){
  if(key_exists(list, map.key))
    return 0;
  map_int_int_ll *current = list;
  int operation_state = put_map(list, map);
  return operation_state;
}

/*Function to insert a map in key, value form into the struct but
doesnt replace if the actual map is already exists in the struct(map) */
int put_dont_replace_kv(map_int_int_ll *list, int key, int value){
  map_int_int map;
  map.key = key;
  map.value = value;
  int operation_state = put_dont_replace(list, map);
  return operation_state;
}

//Delete element at index return -1 if map is empty
int remove_at(map_int_int_ll *list, int index){
  if(empty(list)){
    return -1;
  }
  if(map_size(list) < index){
    return -1;
  }
  map_int_int_ll *current = list, *prev;
  while(current != NULL){
    if(index == 0){
      prev->next = current->next;
      return 1;
    }
    index--;
    prev = current;
    current = current->next;
  }
  return -12;
}

/*Return the last element in the map and delete it return 
(-1:k , -1:v) if null */
map_int_int pop(map_int_int_ll *list){
  map_int_int null_map = {-1, -1};
  map_int_int_ll *current = list, *prev;
  if(empty(list)){
    return null_map;
  }
  if(map_size(list) == 1){
    map_int_int map = current->val;
    current->null = 1;
    return map;
  }
  while(current->next != NULL){
    prev = current;
    current = current->next;
  }
  map_int_int map = current->val;
  prev->next = NULL;

  return map;
}