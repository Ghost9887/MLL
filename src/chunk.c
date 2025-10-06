#include "chunk.h"

void initChunk(Chunk *chunk){
  chunk->capacity = 0;
  chunk->count = 0;
  chunk->instructions = NULL;
}

void addInstruction(Chunk *chunk, uint8_t instruction){
  //check if it fits into the array
  if(chunk->count + 1 > chunk->capacity){
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(chunk->capacity);
    chunk->instructions = GROW_ARRAY(uint8_t, chunk->instructions, oldCapacity, chunk->capacity);
  }
  chunk->instructions[chunk->count] = instruction;
  chunk->count++;
}

void freeChunk(Chunk *chunk){
  FREE_ARRAY(uint8_t, chunk->instructions, chunk->capacity);
  initChunk(chunk);
}
