#include "common.h"
#include "debug.h"
#include "chunk.h"
#include "value.h"
#include "vm.h"

void readFile(const char *fileName);
void getInput();
void scan(char *source);

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

void scan(char *source){
  InterpretResult result = interpret(source);
  free(source);
  if(result == INTERPRET_COMPILE_ERROR) exit(65);
  if(result == INTERPRET_RUNTIME_ERROR) exit(70);
}

void readFile(const char *fileName){
  FILE *file;
  file = fopen(fileName, "r");
  if(file == NULL){
    printf("File not found\n");
    exit(1);
  }
  fseek(file, 0, SEEK_END);
  int fileSize = ftell(file);
  rewind(file);
  char *buffer = malloc(sizeof(char) * fileSize + 1);
  fread(buffer, 1, fileSize, file);
  buffer[fileSize] = '\0';
  fclose(file);
  scan(buffer);
}

void getInput(){
  char *buffer = malloc(sizeof(char) * 1024);
  printf("Enter your code\n");
  printf("> ");
  scanf("%s", buffer);
  scan(buffer);
}

