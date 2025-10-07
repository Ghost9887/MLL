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
  //macro to use math operators
  #define BINARY_OP(op) \
  do { \
    double b = pop(); \
    double a = pop(); \
    push(a op b); \
  }while(false)

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
      case ADD:
        BINARY_OP(+);
        break;
      case SUBTRACT:
        BINARY_OP(-);
        break;
      case MULTIPLY:
        BINARY_OP(*);
        break;
      case DIVIDE:
        BINARY_OP(/);
        break;
      case NEGATE:
        push(-pop());
        break;
      case RETURN:
        printf("Result: %g\n", pop());
        return;
      default:
        break;
    }
  }
}

void freeVM(){
}
