#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position {
  public:
    const int line;
    const int col;

    inline Position(const int line, const int col)
      : line(line), col(col) {};

    inline std::string toString() const {
      return "(l: " + std::to_string(this->line) + ", c: " + std::to_string(this->col) + ")";
    } 
};

#endif