#include "Token.hpp"

std::string Token::getTokenTypeName()
{
  switch (this->type)
  {
  case TokenType::EOF_T:
    return "End of file";
  default:
    return "Invalid token";
  }
}