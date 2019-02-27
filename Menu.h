/*
* The Menu class is in charge of collecting the information
* required to initialize and output the results of the simulation
*/

#ifndef MENU_H
#define MENU_H

#include "Game.h"
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
  void printResults(); //only used for testing
  void setOutput(); //determines output type (with/without pause, or write to file)
  //accessors
  int getRows();
  int getColumns();
  float getDensity();
  string getBoundary();
  string getOutput();
private:
  int rows;
  int columns;
  float density;
  string boundary; //change these to enums?
  string output;
  Game* sim;
};

#endif
