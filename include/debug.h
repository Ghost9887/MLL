#ifndef DEBUG_H
#define DEBUG_H

#include "common.h"
#include "chunk.h"

void deconstructChunk(Chunk *chunk);
int deconstructInstruction(Chunk *chunk, int instructionIndex);

#endif
