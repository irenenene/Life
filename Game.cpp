#include "Menu.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game()
{
  rows = 0;
  columns = 0;
  currentGen = NULL;
  nextGen = NULL;
}

Game::Game(int r, int c)
{
  rows = r;
  columns = c;
  currentGen = new bool* [rows];
  nextGen = new bool* [rows];

  for (int i = 0; i < rows; i++)
  {
    currentGen[i] = new bool[columns];
    nextGen[i] = new bool[columns];
    for (int j = 0; j < columns; j++)
    {
      currentGen[i][j] = false;
      nextGen[i][j] = false;
    }
  }
}

Game::~Game()
{
  cout << "Game destructor" << endl;

  for (int i = 0; i < rows; i++)
  {
    delete [] currentGen[i];
    delete [] nextGen[i];
  }
  delete [] currentGen;
  delete [] nextGen;
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
/*
populate is used during initialization
generates a row - column pair for each cell that is alive during the start of the simulation
if row-column is already populated-> calculates again
*/
void Game::populate(float d)
{
  int aliveCells = int(rows * columns * d);
  int counter = 0;
  srand(time(NULL));
  cout << "Initializing " << aliveCells << " cells" << endl;

  while (counter < aliveCells)
  {
    int r = rand() % rows;
    int c = rand() % columns;
    if (!currentGen[r][c])
    {
      currentGen[r][c] = true;
      counter++;
    }
  }
}
