#include "chunk.h"

void initChunk(Chunk *chunk){
  chunk->capacity = 0;
  chunk->count = 0;
  chunk->instructions = NULL;
  initValueArr(&chunk->values);
  chunk->lineCapacity = 0;
  chunk->lineCount = 0;
  chunk->lines = NULL;
}

void initLines(int *lines, int oldCapacity, int newCapacity){
  for(int i = oldCapacity; i < newCapacity; i++){
    lines[i] = 0;
  }
}

void addInstruction(Chunk *chunk, uint8_t instruction, int line){
  //check if it fits into the array
  if(chunk->count + 1 > chunk->capacity){
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(chunk->capacity);
    chunk->instructions = GROW_ARRAY(uint8_t, chunk->instructions, oldCapacity, chunk->capacity);
  }
  chunk->instructions[chunk->count] = instruction;
  chunk->count++;

  if(chunk->lineCount > 0){
    for(int i = 0; i < chunk->lineCount; i += 2){
      if(chunk->lines[i] == line){
        chunk->lines[i + 1]++;
        return;
      }
    }
  }
  if(chunk->lineCount + 2 > chunk->lineCapacity){
    int oldCapacity = chunk->lineCapacity;
    chunk->lineCapacity = GROW_CAPACITY(oldCapacity);
    chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->lineCapacity);
    initLines(chunk->lines, oldCapacity, chunk->capacity);
  }
  chunk->lines[chunk->lineCount++] = line;
  chunk->lines[chunk->lineCount++] = 1;
}

void addValue(Chunk *chunk, Value value, int line){
  int index = addValueToValueArr(&chunk->values, value);
  if(index < 256){
    addInstruction(chunk, CONSTANT, line);
    addInstruction(chunk, (uint8_t)index, line);
  }else{
    addInstruction(chunk, CONSTANT_LONG, line);
    addInstruction(chunk, (uint8_t)index & 0xFF, line);
    addInstruction(chunk, ((uint8_t)index >> 8) & 0xFF, line);
    addInstruction(chunk, ((uint8_t)index >> 16) & 0xFF, line);
  }
}

void freeChunk(Chunk *chunk){
  freeValueArr(&chunk->values);
  FREE_ARRAY(int, chunk->lines, chunk->lineCapacity);
  FREE_ARRAY(uint8_t, chunk->instructions, chunk->capacity);
  initChunk(chunk);
}
