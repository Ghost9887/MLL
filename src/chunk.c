#include "chunk.h"

void initChunk(Chunk *chunk){
  chunk->capacity = 0;
  chunk->count = 0;
  chunk->instructions = NULL;
  initValueArr(&chunk->values);
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

void addValue(Chunk *chunk, Value value){
  int index = addValueToValueArr(&chunk->values, value);
  if(index < 256){
    addInstruction(chunk, CONSTANT);
    addInstruction(chunk, (uint8_t)index);
  }else{
    addInstruction(chunk, CONSTANT_LONG);
    addInstruction(chunk, (uint8_t)index & 0xFF);
    addInstruction(chunk, ((uint8_t)index >> 8) & 0xFF);
    addInstruction(chunk, ((uint8_t)index >> 16) & 0xFF);
  }
}

void freeChunk(Chunk *chunk){
  freeValueArr(&chunk->values);
  FREE_ARRAY(uint8_t, chunk->instructions, chunk->capacity);
  initChunk(chunk);
}
