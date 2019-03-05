/*
* The Menu class is in charge of collecting the information
* required to initialize and output the results of the simulation
*/

#ifndef MENU_H
#define MENU_H

#include "Game.h"
#include "Classic.h"
#include "Donut.h"
#include "Mirror.h"
#include <iostream>

using namespace std;

class Menu
{
public:
  Menu();
  ~Menu();
  void initialize(); //prompts for the initial configuration of the system
  void setParameter(int*); //used for int parameter such as rows or columns
  void setDensity();
  void setBoundary();
  void setOutputType(); //determines output type (with/without pause, or write to file)
  void fromRandom(); //creates a new simulation from user-defined inputs
  void fromFile(); //creates a new simulation from a user-specified file
  void runWithPause();
  void runWithEnter();
  void outToFile();
  static const int ITERATIONS = 10;
  static const int MILLISECONDS = 1000;
  static const int MAX_LINE = 65536;

private:
  int rows;
  int columns;
  float density;
  string fileString;
  Game* sim;
};

#endif
