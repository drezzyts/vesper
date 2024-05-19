#include "Lexer.hpp"
#include "Token.hpp"
#include <vector>

Tokens_t Lexer::readTokens()
{
  while (!this->isEof())
  {
    this->start = this->current;
    this->readToken();
  }

  Position pos(this->line, this->current);
  Token eof(TokenType::EOF_T, "\0", pos);
  this->tokens.push_back(eof);

  return this->tokens;
}

void Lexer::readToken()
{
  current++;
}

bool Lexer::isEof()
{
  return this->current >= (int)this->source.length();
}
