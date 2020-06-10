#include "map_structs.h"

typedef struct s_map_int_int{
  map_int_int val;
  struct s_map_int_int *next;
}map_int_int_ll;

typedef struct s_map_string_string{
  map_string_string val;
  struct s_map_string_string *next;
}map_string_string_ll;

typedef struct s_map_int_string{
  map_int_string val;
  struct s_map_int_string *next;
}map_int_string_ll;

typedef struct s_map_string_int{
  map_string_int val;
  struct s_map_string_int *next;
}map_string_int_ll;
