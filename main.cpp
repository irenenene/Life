/*
Irene Liu
2313260
irliu@chapman.edu
CPSC 350-02
Assignment: 2

*/

#include "Menu.h"
#include "Game.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{
  Menu mainMenu;
  mainMenu.initialize();

  cout << "Press any key to exit. ";
  getchar();
  return 0;
}
