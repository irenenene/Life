#ifndef MIRROR_H
#define MIRROR_H

#include "Game.h"
#include <iostream>

using namespace std;

class Mirror : public Game
{
public:
  Mirror();
  Mirror(int r, int c);
  ~Mirror();
  void calcNeighbor();
private:
  int northWrap(int rowNum);
  int eastWrap(int colNum);
  int southWrap(int rowNum);
  int westWrap(int colNum);
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
