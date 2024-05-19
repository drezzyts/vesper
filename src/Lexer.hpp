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

  bool isEof();
  bool match(char expected);
  
  void readLexeme(std::string* dest);
  void readToken();
  void pushToken(TokenType type);
  void readString();
  void readNumber();

  char next();
  char peek(int offset);
  inline char peek() { return this->peek(0); };

public:
  inline Lexer(const std::string &source)
      : source(source), tokens() {}
      
  Tokens_t readTokens();    
};

#endif