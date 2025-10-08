#include "scanner.h"

Scanner scanner;

Token scanToken(){
}

void initScanner(const char *source){
  scanner.start = source;
  scanner.current = source;
  scanner.line = 1;
}


