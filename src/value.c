#include "value.h"

void initValueArr(ValueArr *valueArr){
  valueArr->capacity = 0;
  valueArr->count = 0;
  valueArr->values = NULL;
}

int addValueToValueArr(ValueArr *valueArr, Value value){
  if(valueArr->count + 1 > valueArr->capacity){
    int oldCapacity = valueArr->capacity;
    valueArr->capacity = GROW_CAPACITY(valueArr->capacity);
    valueArr->values = GROW_ARRAY(Value, valueArr->values, oldCapacity, valueArr->capacity);
  }
  valueArr->values[valueArr->count] = value;
  valueArr->count++; 
  return valueArr->count - 1;
}

void freeValueArr(ValueArr *valueArr){
  FREE_ARRAY(Value, valueArr->values, valueArr->capacity);
  initValueArr(valueArr);
}
