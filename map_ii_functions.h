#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "map_lists.h"


//Function test if the linked list is empty returns 1 if true and 0 if not
int empty(map_int_int_ll *list) {
  if(list->val == NULL)
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
//Function to test if a given map element exists int the linked list
int exists(map_int_int_ll *list, map_int_int map){
  map_int_int_ll *current = list;
  //Test if the map exists in the first node of the linked list
  //Looping through the elements of the linked list to see if there's a match of the passed element
  while(current != NULL){
    if(current->val.key == map.key && current->val.value == map.value){
      return 1;
    }
    current = current->next;
  }
  return 0;
}

int genesis_node(map_int_int_ll *list, int key, int value){
  map_int_int map;
  map.key = key;
  map.value = value;
  list->val = map;
  return 1;
}

//Function to create a new map element and add it to a given list
int put(map_int_int_ll *list, int key, int value){
  map_int_int_ll *current = list;
  map_int_int_ll *node = (map_int_int_ll*)malloc(sizeof(map_int_int_ll));
  map_int_int map;
  map.key = key;
  map.value = value;
  if(exists(list, map))
    return 0;
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
  if(exists(list, map))
    return 0;
  map_int_int_ll *node = (map_int_int_ll*)malloc(sizeof(map_int_int_ll));
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

//Function to get the size of the linkedlist
int map_size(map_int_int_ll *list){
  int i = 0;
  map_int_int_ll *current = list;
  while(current != NULL){
    i++;
    current = current->next;
  }
  return i;
}

//Function return the keyset of the  given map
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
  map_int_int_ll *current = list;
  while(current != NULL){
    if(current->val.key == key){
      return current->val.value;
    }
    current = current->next;
  }
  return -1;
}
