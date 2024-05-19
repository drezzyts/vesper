#include <iostream>
#include <string>

#include "Vesper.hpp"
#include "TokenType.hpp"

int main(int argc, char* argv[]) {
  Vesper program;
  std::string filename;

  switch (argc) {
    case 1:
      return (int) program.runRepl();
    case 2:
      filename = std::string(argv[1]);

      if (filename == "--help") {
        program.showHelp();
        return 0;
      }
      
      return (int) program.runFile(filename);
    default:
      program.showHelp();
      return 0;
  }
}

std::string getTokenTypeName(const TokenType type) {
  switch (type)
  {
    case TokenType::EOF_T: return "End of file";
    default: return "Invalid token";
  }
}