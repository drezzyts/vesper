#include "Lexer.hpp"
#include "Token.hpp"
#include "Vesper.hpp"

#include <vector>

Tokens_t Lexer::readTokens()
{
  while (!this->isEof())
  {
    this->readToken();
    this->start = this->current;
  }

  Position pos(this->line, this->current);
  Token eof(TokenType::EOF_T, "\0", pos);
  this->tokens.push_back(eof);

  return this->tokens;
}

void Lexer::readLexeme(std::string *dest)
{
  char *lexeme = new char[this->current - this->start + 1];
  this->source.copy(lexeme, this->current - this->start, this->start);
  lexeme[this->current - this->start] = '\0';
  
  *dest = std::string(lexeme);

  delete[] lexeme;
}

void Lexer::readToken()
{
  char curr = this->next();

  switch (curr)
  {
  case '(':
    this->pushToken(TokenType::LEFT_PAREN);
    break;
  case ')':
    this->pushToken(TokenType::RIGHT_PAREN);
    break;
  case '{':
    this->pushToken(TokenType::LEFT_BRACE);
    break;
  case '}':
    this->pushToken(TokenType::RIGHT_BRACE);
    break;
  case ',':
    this->pushToken(TokenType::COMMA);
    break;
  case '.':
    this->pushToken(TokenType::DOT);
    break;
  case ';':
    this->pushToken(TokenType::SEMICOLON);
    break;
  case '+':
    this->pushToken(TokenType::PLUS);
    break;
  case '-':
    this->pushToken(TokenType::MINUS);
    break;
  case '*':
    this->pushToken(TokenType::STAR);
    break;
  case '!':
    this->pushToken(this->match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
    break;
  case '=':
    this->pushToken(this->match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
    break;
  case '<':
    this->pushToken(this->match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
    break;
  case '>':
    this->pushToken(this->match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
    break;
  case '/':
    if (this->match('/'))
      while (this->peek() != '\n' && !this->isEof())
        this->next();
    else
      this->pushToken(TokenType::SLASH);
    break;
  case ' ':
  case '\r':
  case '\t':
    break;
  case '\n':
    this->line++;
    break;
  case '"':
    this->readString();
    break;
  default:
    Position pos(this->line, this->current);

    if (isdigit(curr))
      readNumber();
    else
      Vesper::report(pos, " --> [lexer]", "Unexpected char founded while lexing: " + this->source.substr(this->start, this->current));
    break;
  }
}

void Lexer::pushToken(TokenType type)
{
  
  std::string lexeme;
  this->readLexeme(&lexeme);

  Position pos(this->line, this->current);
  Token token(type, lexeme, pos);

  this->tokens.push_back(token);
}

void Lexer::readString()
{
  while (this->peek() != '"' && !this->isEof())
  {
    if (this->peek() == '\n')
      line++;
    this->next();
  }

  if (this->isEof())
  {
    Position pos(this->line, this->current);
    Vesper::report(pos, " --> [lexer]", "Unterminated string.");
    return;
  }

  this->next();

  std::string lexeme;
  this->readLexeme(&lexeme);

  Position pos(this->line, this->current);
  Token token(TokenType::STRING, lexeme, pos);

  this->tokens.push_back(token);
}

void Lexer::readNumber()
{
  TokenType type = TokenType::INTEGER;

  while (isdigit(this->peek())) this->next();

  if (this->peek() == '.' && isdigit(this->peek(1))) {
    type = TokenType::FLOAT;
    this->next();
    
    while (isdigit(this->peek())) this->next();
  }

  std::string lexeme;
  this->readLexeme(&lexeme);

  Position pos(this->line, this->current);
  Token token(type, lexeme, pos);

  this->tokens.push_back(token);
}

char Lexer::next()
{
  return this->source.at(this->current++);
}

char Lexer::peek(int offset)
{
  int pos = this->current + offset;

  if (pos >= (int) this->source.length())
    return '\0';
  return this->source.at(pos);
}

bool Lexer::isEof()
{
  return this->current >= (int)this->source.length();
}

bool Lexer::match(char expected)
{
  if (this->isEof())
    return false;
  if (this->source.at(this->current) != expected)
    return false;

  current++;
  return true;
}
