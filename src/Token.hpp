#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>
#include <vector>

#include "TokenType.hpp"
#include "Position.hpp"

class Token
{
public:
  const TokenType type;
  const std::string lexeme;
  const Position pos;

  inline Token(const TokenType type, const std::string lexeme, Position pos)
      : type(type), lexeme(lexeme), pos(pos){};

  inline std::string toString()
  {
    return getTokenTypeName(this->type) + ": " + this->lexeme;
  }

  inline void write()
  {
    std::cout << this->pos.toString() << "--> " << this->toString() << std::endl;
  }
};

typedef std::vector<Token> Tokens_t;

#endif