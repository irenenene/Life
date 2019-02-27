#include "Menu.h"
#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
{
  rows = 0;
  columns = 0;
  currentGen = NULL;
  //nextGen = NULL;
}

Game::Game(int r, int c)
{
  rows = r;
  columns = c;
  currentGen = new bool* [rows];

  for (int i = 0; i < rows; i++)
  {
    currentGen[i] = new bool[columns];
    for (int j = 0; j < columns; j++)
    {
      currentGen[i][j] = false;
    }
  }
}

Game::~Game()
{
  cout << "Game destructor" << endl;

  for (int i = 0; i < rows; i++)
  {
    delete [] currentGen[i];
  }
  delete [] currentGen;
}

string Game::toString()
{
  string out = "";

  if (currentGen != NULL)
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
      {
        if(currentGen[i][j])
          out += "X";
        else
          out += "-";
      }
      out += "\n";
    }
  }

  return out;
}
