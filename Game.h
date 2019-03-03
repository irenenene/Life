/*
* The game class is an abstract class that will be extended by the 3 different modes-
* each implementing their own versions of calcNeighbor()
*/

#ifndef GAME_H
#define GAME_H

#include <iostream>

using namespace std;

class Game
{
public:
  Game();
  Game(int r, int c);
  ~Game();
  //void calcNeighbor();
  void populate(float d);
  //void populate(File);
  string toString(); //currentGen
  /*
  clone();
  equals();
  */

protected:
  bool** currentGen; //basically a 2-d array; a value of true means the cell is alive
  bool** nextGen;
  int rows;
  int columns;

};

#endif
