#include "memory.h"

void *reallocate(void *pointer, size_t oldCapacity, size_t newCapacity){
  
  if(newCapacity <= 0){
    if(oldCapacity <= 0) return NULL; //check if there ever was any memory allocated
    free(pointer);
    return NULL;
  }
  void *result = realloc(pointer, newCapacity);
  if(result == NULL) exit(1);
  return result;
}
