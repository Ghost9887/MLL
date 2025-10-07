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
  addInstruction(&chunk, ADD, 10);
  //50
  addValue(&chunk, 10.0, 20);
  addInstruction(&chunk, SUBTRACT, 10);
  //40
  addValue(&chunk, 2.0, 20);
  addInstruction(&chunk, MULTIPLY, 20);
  //80
  addValue(&chunk, 4.0, 20);
  addInstruction(&chunk, DIVIDE, 20);
  //20
  addInstruction(&chunk, NEGATE, 10);
  //-20
  addInstruction(&chunk, RETURN, 10);

  initVM(&chunk);
  run();
  freeChunk(&chunk);
  return 0;
}
