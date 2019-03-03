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
  virtual void calcNeighbor() =0;
  void populate(float d);
  //void populate(File);
  string toString(); //currentGen
  string toStringNext(); //for nextGen testing purposes
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
