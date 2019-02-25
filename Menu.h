#ifndef MENU_H
#define MENU_H

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
private:
  bool exit;
  int rows;
  int columns;
  float density;
  string boundary;
};

#endif
