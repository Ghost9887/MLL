#include "debug.h"

int printCommonInstruction(Chunk *chunk, int instructionIndex, const char *instruction){
  printf("%04d -> |%s|\n", instructionIndex, instruction);
  return instructionIndex + 1;
}

int printCommonConstant(Chunk *chunk, int instructionIndex, const char *instruction){
  printf("%04d -> |%s|\n", instructionIndex, instruction);
  return instructionIndex + 1;
}

int printInstructions(Chunk *chunk, int instructionIndex){
  switch(chunk->instructions[instructionIndex]){
    case RETURN:
      return printCommonInstruction(chunk, instructionIndex, "RETURN");
    case CONSTANT:
      return printCommonConstant(chunk, instructionIndex, "CONSTANT");
    default:
      return instructionIndex + 1;
  }
}

void deconstructChunk(Chunk *chunk){
  for(int index = 0; index < chunk->count;){
    index = printInstructions(chunk, index);
  }
}
