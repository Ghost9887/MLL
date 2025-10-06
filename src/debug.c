#include "debug.h"

int printCommonInstruction(int instructionIndex, const char *instruction){
  printf("<%s>\n", instruction);
  return instructionIndex + 1;
}

int printCommonConstant(int instructionIndex, const char *instruction, Value value){
  printf("<%s> '%g'\n", instruction, value);
  return instructionIndex + 2;
}

int printLongConstant(int instructionIndex, const char *instruction, Chunk *chunk){
  int index = chunk->instructions[instructionIndex + 1] |
              chunk->instructions[instructionIndex + 2] << 8|
              chunk->instructions[instructionIndex + 3] << 16;

  Value value = chunk->values.values[index];
  printf("<%s> '%g'\n", instruction, value);
  return instructionIndex + 4;
}

int getLine(Chunk *chunk, int instructionIndex) {
  int offset = 0;
  for (int i = 0; i < chunk->lineCount; i += 2) {
    int line = chunk->lines[i];
    int count = chunk->lines[i + 1];
    if (instructionIndex < offset + count) {
      return line;
    }
    offset += count;
  }
  return -1;
}

int deconstructInstruction(Chunk *chunk, int instructionIndex){
  printf("%04d ", instructionIndex);
  //show the line where a error happened
  int line = getLine(chunk, instructionIndex);
  if(instructionIndex > 0 && line == getLine(chunk, instructionIndex - 1)){
    printf("  | ");
  }else{
    printf("%4d ", line);
  }
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
    index = deconstructInstruction(chunk, index);
  }
}
