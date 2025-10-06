#include "debug.h"

int printCommonInstruction(int instructionIndex, const char *instruction){
  printf("%04d -> |%s|\n", instructionIndex, instruction);
  return instructionIndex + 1;
}

int printCommonConstant(int instructionIndex, const char *instruction, Value value){
  printf("%04d -> |%s| '%g'\n", instructionIndex, instruction, value);
  return instructionIndex + 2;
}

int printLongConstant(int instructionIndex, const char *instruction, Chunk *chunk){
  int index = chunk->instructions[instructionIndex + 1] |
              chunk->instructions[instructionIndex + 2] << 8|
              chunk->instructions[instructionIndex + 3] << 16;

  Value value = chunk->values.values[index];
  printf("%04d -> |%s| '%g'\n", instructionIndex, instruction, value);
  return instructionIndex + 4;
}

int printInstructions(Chunk *chunk, int instructionIndex){
  switch(chunk->instructions[instructionIndex]){
    case RETURN:
      return printCommonInstruction(instructionIndex, "RETURN");
    case CONSTANT:
      Value value = (Value)chunk->values.values[chunk->instructions[instructionIndex + 1]];
      return printCommonConstant(instructionIndex, "CONSTANT", value);
    case CONSTANT_LONG:
      return printLongConstant(instructionIndex, "CONSTANT_LONG", chunk);
    default:
      return instructionIndex + 1;
  }
}

void deconstructChunk(Chunk *chunk){
  for(int index = 0; index < chunk->count;){
    index = printInstructions(chunk, index);
  }
}
