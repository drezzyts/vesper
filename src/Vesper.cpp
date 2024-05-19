#include <iostream>
#include <fstream>
#include <sstream>

#include "Lexer.hpp"
#include "Vesper.hpp"
#include "Position.hpp"

bool Vesper::hadError = false;

VesperTaskResult Vesper::run(const std::string &source)
{
  Lexer lexer(source);
  Tokens_t tokens = lexer.readTokens();

  for (Token token : tokens)
    token.write();

  return VesperTaskResult::RUN_SUCCESS;
}

void Vesper::error(const Position &pos, const std::string &message)
{
  Vesper::report(pos, "", message);
}

void Vesper::report(const Position &pos, const std::string &where, const std::string &message)
{
  std::cerr << pos.toString() << " Error" + where + ": " + message << std::endl;
  Vesper::hadError = true;
}

VesperTaskResult Vesper::runRepl()
{
  std::string input;
  std::cout << "vesper - repl v0.1: \n\t* Quit --> :q\n"
            << std::endl;

  do
  {
    std::cout << ">> ";
    std::getline(std::cin, input);

    if (input == ":q")
      break;

    this->run(input);
  } while (input != ":q");

  return VesperTaskResult::RUN_SUCCESS;
}

VesperTaskResult Vesper::runFile(const std::string &filename)
{
  std::ifstream file(filename);
  std::stringstream buffer;
  std::string content;

  if (!file)
  {
    Vesper::error({-1, -1}, "An unexpected error occurred while reading the file.");
    return VesperTaskResult::RUN_FAILED;
  }

  buffer << file.rdbuf();
  content = buffer.str();

  file.close();

  std::cout << content << std::endl;
  this->run(content);
  if (Vesper::hadError)
    return VesperTaskResult::RUN_FAILED;
  else 
    return VesperTaskResult::RUN_SUCCESS;
}
