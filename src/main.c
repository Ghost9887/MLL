#include "common.h"
#include "debug.h"
#include "chunk.h"
#include "value.h"
#include "vm.h"

void readFile(const char *fileName);
void getInput();
void scan(const char *source);

int main(int argc, char *argv[]){

  if(argc == 2) readFile(argv[1]);
  else if(argc == 1) getInput();
  else fprintf(stderr, "Usage: ./a.out 'file' | ./a.out\n");

  /*
  Chunk chunk;
  initChunk(&chunk);

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
  */
  return 0;
}

void scan(const char *source){
}

void readFile(const char *fileName){
}

void getInput(){
}

