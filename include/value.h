#ifndef VALUE_H
#define VALUE_H

#include "memory.h"

typedef double Value;

typedef struct ValueArr{
  int capacity;
  int count;
  Value *values;
}ValueArr;

void initValueArr(ValueArr *valueArr);
int addValueToValueArr(ValueArr *valueArr, Value value);
void freeValueArr(ValueArr *valueArr);

#endif
