#include "common.h"
#include "debug.h"
#include "chunk.h"
#include "value.h"
#include "vm.h"


int main(int agrc, char *argv[]){
  Chunk chunk;
  initChunk(&chunk);

  //addInstruction(&chunk, RETURN, 10);
  addValue(&chunk, 20.0, 20);
  addValue(&chunk, 30.0, 20);
  addValue(&chunk, 40.0, 30);
  addInstruction(&chunk, RETURN, 10);

  initVM(&chunk);
  run();
  freeChunk(&chunk);
  return 0;
}
