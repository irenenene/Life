#ifndef CLASSIC_H
#define CLASSIC_H

#include "Game.h"
#include <iostream>

using namespace std;

class Classic : public Game
{
public:
  Classic();
  Classic(int r, int c);
  ~Classic();
  void calcNeighbor(); //sums the results of the functions below to determine the next gen
private:
  //the following functions return 1 if the neighboring cell is occupied and 0 otherwise
  int north(int rowNum, int colNum);
  int northeast(int rowNum, int colNum);
  int east(int rowNum, int colNum);
  int southeast(int rowNum, int colNum);
  int south(int rowNum, int colNum);
  int southwest(int rowNum, int colNum);
  int west(int rowNum, int colNum);
  int northwest(int rowNum, int colNum);
};

#endif
