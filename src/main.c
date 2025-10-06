#include "common.h"
#include "debug.h"
#include "chunk.h"


int main(int agrc, char *argv[]){
  Chunk chunk;
  initChunk(&chunk);

  addInstruction(&chunk, RETURN);
  addInstruction(&chunk, CONSTANT);
  deconstructChunk(&chunk);

  freeChunk(&chunk);
  return 0;
}
