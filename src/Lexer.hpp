#ifndef LEXER_H
#define LEXER_H

#include "Token.hpp"
#include <string>

class Lexer
{
private:
  const std::string source;
  Tokens_t tokens;

  int start = 0;
  int current = 0;
  int line = 1;

  void readToken();
  bool isEof();

public:
  inline Lexer(const std::string source)
      : source(source), tokens(){};
      
  Tokens_t readTokens();    
};

#endif