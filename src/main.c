#include "common.h"
#include "debug.h"
#include "chunk.h"
#include "value.h"


int main(int agrc, char *argv[]){
  Chunk chunk;
  initChunk(&chunk);

  addInstruction(&chunk, RETURN, 10);
  addValue(&chunk, 20.0, 20);

  deconstructChunk(&chunk);
  freeChunk(&chunk);
  return 0;
}
