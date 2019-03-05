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
  void update(); //called after calcNeighbor
  void populate(float d);
  void populate(string fname);
  string toString(); //currentGen
  string toStringNext(); //for nextGen testing purposes
  static const int MAX_LINE = 65536;
  int getGenNum();
  bool isEmpty();
  bool isStable();

protected:
  bool** currentGen; //basically a 2-d array; a value of true means the cell is alive
  bool** nextGen;
  bool** temp; //used for shadow paging
  int rows;
  int columns;
  int genNum;

};

#endif
