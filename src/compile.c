#include "compile.h"

void compile(const char *source){
  Chunk chunk;
  initChunk(&chunk);
  initScanner(source);
  int line = -1;
  //only prints for now
  printf("Tokens:\n");
  while(true){
    Token token = scanToken();
    if(token.line != line){
      printf("%4d", token.line);
      line = token.line;
    } else {
      printf("  | ");
    }
    printf(" %2d '%.*s'\n", token.type, token.length, token.start);
    if(token.type == TOKEN_PLUS){
      addInstruction(&chunk, ADD, line);
    }
    else if(token.type == TOKEN_NUMBER){
      char *number = malloc(sizeof(char) * token.length);
      for(int i = 0; i < token.length; i++){
        number[i] = *token.start;
        token.start++;
      }
      Value value = (Value)(atoi(number));
      addValue(&chunk, value, line);
      free(number);
    }
    else if(token.type == TOKEN_EOF){
      addInstruction(&chunk, RETURN, line);
      break;
    }
  }
  printf("\nInstructions:\n");
  initVM(&chunk);
  run();
  freeChunk(&chunk);
  //freeVM();
}

