#include "Menu.h"
#include "Game.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{
  Menu mainMenu;
  mainMenu.initialize();

  //mainMenu.printResults();

  cout << "Press any key to exit. ";
  getchar();
  return 0;
}
