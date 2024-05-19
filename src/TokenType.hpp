#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

#include <string>

enum class TokenType {
  EOF_T
};

std::string getTokenTypeName(const TokenType type);

#endif