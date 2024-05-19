#ifndef VESPER_H
#define VESPER_H

#include <string>
#include "Position.hpp"

enum class VesperTaskResult
{
  RUN_SUCCESS,
  RUN_FAILED
};

class Vesper
{
  VesperTaskResult run(const std::string &source);

public:
  static bool hadError;
  static void error(const Position &pos, const std::string &message);
  static void report(const Position &pos, const std::string &where, const std::string &message);

  VesperTaskResult runRepl();
  VesperTaskResult runFile(const std::string &filename);

  inline void showHelp()
  {
    std::cout << "Usage:\n\t* Execute a file --> vesper [filename]\n\t* Show help --> vesper --help\n\t* Enter in REPL --> vesper" << std::endl;
  };
};

#endif