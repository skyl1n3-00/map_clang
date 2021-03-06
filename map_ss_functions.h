#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "map_lists.h"

//Struct to hold the keyset of strings
typedef struct keys {
    char *key;
}keys;

/*
int empty(*list)
void print(*list)
int equals(map1, map2)
int exists(*list, map)
int exists_key(*list, key)
int put_kv(list, key, value)
int put_map(*list, map)
int map_size(*list)
keys* key_set(*list)
char* get_value(key)
int put_dont_replace_map(*list, map)
int put_dont_replace_kv(*list, key, value)
int remove_at(**list, position)
int remove_key(**list, key)
map_int_string pop(**list)
int clear(**list)
*/

//Function tests if the given linked list is empty returns 1 if true and 0 if not
int empty(map_string_string_ll *list) {
  if(list->null == 0)
    return 1;
  return 0;
}

//Function to print the map
void print(map_string_string_ll *list){
    map_string_string_ll *current = list;
    while(current != NULL){
        printf("[%s, %s]\n", current->val.key, current->val.value);
        current = current->next;
    }
}

//Function to test of two given maps are equal return 1 if yes otherwise 0
int equals(map_string_string map1, map_string_string map2) {
  if(strcmp(map1.key, map2.key) != 0)
    return 0;

  if(strcmp(map1.value, map2.value) != 0)
    return 0;

  return 1;
}

//Function to test if a given map element exist in the map struct
int exists(map_string_string_ll *list, map_string_string map) {
  map_string_string_ll *current = list;
  while(current != NULL){
    if(equals(current->val, map))
      return 1;
    current = current->next;
  }
  return 0;
}

/*Function to test if a given key of map element exists
in the map struct return 1 if yes otherwise 0 */
int key_exists(map_string_string_ll *list, char *key){
  map_string_string_ll *current = list;
  while(current != NULL){
    if(strcmp(current->val.key, key) == 0)
      return 1;
    current = current->next;
  }
  return 0;
}

//Function to insert the first element in map struct
int genesis_node(map_string_string_ll *list, map_string_string map){
  if(list->null == 1)
    return 0;
  list->val = map;
  list->null = 1;
  return 1;
}

//Function to insert a map element (k, v) int the given map struct
int put_kv(map_string_string_ll *list, char *key, char *value){
  int operation_state;
  map_string_string_ll *current = list;
  map_string_string map = {key, value};

  //We check if the list is empty, if true we insert the first element
  if(empty(current)){
    operation_state = genesis_node(current, map);
    list = current;
    return operation_state;
  }

  //We check if the key already exists in the list, if true override the old value
  if(key_exists(current, key) == 1){
    while(current != NULL){
       if(strcmp(current->val.key, key) == 0){
         current->val.value = map.value;
       }
       current = current->next;
    }
    return 1;
  }
  //We create a new node and then insert it in the list
  map_string_string_ll *node = (map_string_string_ll *)malloc(sizeof(map_string_string_ll));
  node->val = map;
  node->next = NULL;
  while(1){
    if(current->next == NULL){
      current->next = node;
      break;
    }
    current = current->next;
  }
  return 1;
}

//Function to insert created map element to a given map struct
int put_map(map_string_string_ll *list, map_string_string map){
  int operation_state = put_kv(list, map.key, map.value);
  return operation_state;
}

// //Function to get the size of the map
int map_size(map_string_string_ll *list){
  int i = 0;
  if(list == NULL)
    return 0;
  map_string_string_ll *current = list;
  while(current != NULL){
    i++;
    current = current->next;
  }
  return i;
}

//Function returns the keyset of the given map
keys* key_set(map_string_string_ll *list){
  map_string_string_ll *current = list;
  keys *keys = (struct keys *) malloc(sizeof(keys) * map_size(current));
  int i = 0;
  while(current != NULL) {
    (keys + i)->key = current->val.key;
    current = current->next;
    i++;
  }
  return keys;
}

/*Function to return the value of a give key return "Doesnt exist" 
if the given key doesnt exists in the list */
char* get_value(map_string_string_ll *list, char *key){
  if(!key_exists(list, key))
    return "Doesn't exist";
  map_string_string_ll *current = list;
  while(current != NULL){
    if(current->val.key == key){
      return current->val.value;
    }
    current = current->next;
  }
  return "Doesn't exist";
}

/*Function to insert a map node into the struct but doesnt replace if 
the actual map is already exists in the struct(map)*/
int put_dont_replace(map_string_string_ll *list, map_string_string map){
  if(key_exists(list, map.key))
    return 0;
  int operation_state = put_map(list, map);
  return operation_state;
}

/*Function to insert a map in key, value form into the struct but
doesnt replace if the actual map is already exists in the struct(map) */
int put_dont_replace_kv(map_string_string_ll *list, char *key, char *value){
  map_string_string map;
  map.key = key;
  map.value = value;
  int operation_state = put_dont_replace(list, map);
  return operation_state;
}

/*Remove the element of the given key, if not exists return 0
otherwise 1*/
int remove_key(map_string_string_ll **list, char *key){
  if(empty(*list)) {
    return 0;
  }

  if(!key_exists(*list, key)){
    return 0;
  }
  map_string_string_ll *current = *list, *new_list;
  new_list = (map_string_string_ll*)malloc(sizeof(map_string_string_ll));
  //We test if the given key matches the first key of the map 
  if(current->val.key == key){
    current = current->next;
    while(current != NULL){
      put_map(new_list, current->val);
      current = current->next;
    }
    *list = new_list;
    return 1;
  }
  map_string_string_ll *prev;
  while(1){
    if(current->val.key == key){
      prev->next = current->next;
      return 1;
    }
    prev = current;
    current = current->next;
  }

  return 0;
}

//Delete element at index return -1 if map is empty
int remove_at(map_string_string_ll **list, int index){
  if(empty(*list)){
    return -1;
  }
  if(map_size(*list) <= index){
    return -1;
  }
  map_string_string_ll *current = *list, *new_list;
  new_list = (map_string_string_ll*)malloc(sizeof(map_string_string_ll));
  if(index == 0){
    current = current->next;
    while(current != NULL){
      put_map(new_list, current->val);
      current = current->next;
    }
    *list = new_list;
    return 1;
  }
  map_string_string_ll *prev;
  while(1){
    if(index == 0){
      prev->next = current->next;
      return 1;
    }
    index--;
    prev = current;
    current = current->next;
  }
  return -1;
}

/*Return the last element in the map and delete it return 
(-1:k, null:v) if null */
map_string_string pop(map_string_string_ll *list){
  map_string_string null_map = {NULL, NULL};
  map_string_string_ll *current = list, *prev;
  if(empty(list)){
    return null_map;
  }
  if(map_size(list) == 1){
    map_string_string map = current->val;
    current->null = 1;
    return map;
  }
  while(current->next != NULL){
    prev = current;
    current = current->next;
  }
  map_string_string map = current->val;
  prev->next = NULL;

  return map;
}

/*Function to clear the list return 1 if operation is done 
otherwise 0*/
int clear(map_string_string_ll **list){
  *list = NULL;
  if(list == NULL)
    return 1;
  return 0;
}