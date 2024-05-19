#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

#include <string>
#include <unordered_map>

enum class TokenType
{
  // Punctuators
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  // Operators
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // Literals
  IDENTIFIER, CHAR, STRING, INTEGER, FLOAT,

  // Keywords.
  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
  PUTS, RETURN, SUPER, SELF, TRUE, LET, WHILE,

  // Others
  INVALID, EOF_T 
};

#endif