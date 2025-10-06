#ifndef CHUNK_H
#define CHUNK_H

#include "common.h"
#include "memory.h"
#include "value.h"

typedef enum Instructions{
  RETURN,
  CONSTANT,
  CONSTANT_LONG
}Instructions;

typedef struct Chunk{
  int capacity;
  int count;
  uint8_t *instructions;
  ValueArr values;
  int lineCapacity;
  int lineCount;
  int *lines;
}Chunk;

void initChunk(Chunk *chunk);
void addInstruction(Chunk *chunk, uint8_t instruction, int line);
void addValue(Chunk *chunk, Value value, int line);
void freeChunk(Chunk *chunk);

#endif
