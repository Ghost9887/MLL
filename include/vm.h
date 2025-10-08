#ifndef VM_H
#define VM_H

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "compile.h"

#define STACK_MAX 256

typedef struct VM{
  Chunk *chunk;
  uint8_t *ip;
  Value stack[STACK_MAX];
  Value *stackTop;
}VM;

typedef enum InterpretResult{
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
}InterpretResult;

void initVM();
void run();
InterpretResult interpret(const char *source);
void freeVM();

#endif
