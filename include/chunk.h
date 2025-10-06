#ifndef CHUNK_H
#define CHUNK_H

#include "common.h"
#include "memory.h"

typedef enum Instructions{
  RETURN,
  CONSTANT
}Instructions;

typedef struct Chunk{
  int capacity;
  int count;
  uint8_t *instructions;
}Chunk;

void initChunk(Chunk *chunk);
void addInstruction(Chunk *chunk, uint8_t instruction);
void freeChunk(Chunk *chunk);

#endif
