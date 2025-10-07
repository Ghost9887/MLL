#include "vm.h"

VM vm;

void initVM(Chunk *chunk){
  vm.chunk = chunk;
  vm.ip = chunk->instructions;
  vm.stackTop = vm.stack;
}

Value pop(){ 
  vm.stackTop--;
  return *vm.stackTop;
}

void push(Value value){
  *vm.stackTop = value;
  vm.stackTop++;
}

uint8_t getInstruction(){
  return *vm.ip++;
}

void run(){
  while(true){
    uint8_t instruction = getInstruction(); 
    int index = (int)(vm.ip - vm.chunk->instructions - 1);
    //printf("index: %d\n", index);
    //debug mode
    #ifdef DEBUG_MODE
      deconstructInstruction(vm.chunk, index);
    #endif
    switch(instruction){
      case CONSTANT:
        Value value = vm.chunk->values.values[*vm.ip++];
        //printf("stack push: %g\n", value);
        push(value);
        break;
      case RETURN:
        return;
      default:
        break;
    }
  }
}

void freeVM(){
}
