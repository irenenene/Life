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
//  void calcNeighbor();
//  void populate(float);

  string toString(); //currentGen
  /*
  clone();
  equals();
  */
  //void populate(File);

private:
  bool** currentGen; //will be pointing to an array of bool pointers- basically a 2-d array
//  bool** nextGen;
  int rows;
  int columns;

};

#endif
