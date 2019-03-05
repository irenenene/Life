#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

Game::Game()
{
  rows = 0;
  columns = 0;
  currentGen = NULL;
  nextGen = NULL;
  temp = NULL;
  genNum = 0;
}

Game::Game(int r, int c)
{
  rows = r;
  columns = c;
  currentGen = new bool* [rows];
  nextGen = new bool* [rows];
  temp = NULL;
  genNum = 0;

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

void Game::update()
{
  temp = currentGen;
  currentGen = nextGen;
  nextGen = temp;
}

string Game::toString()
{
  string out = to_string(genNum);
  out += '\n';

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

string Game::toStringNext()
{
  string out = "";

  if (nextGen != NULL)
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
      {
        if(nextGen[i][j])
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

void Game::populate(string fname)
{
  ifstream inFile;
  inFile.open(fname);
  bool validFile = true;

  if(!inFile)
  {
    cout << "Error finding file. " << endl;
    validFile = false;
  }
  else
  {
    char letter;
    int r = 0;
    int c = 0;
    //ignore first 2 lines
    inFile.ignore(MAX_LINE, '\n');
    inFile.ignore(MAX_LINE, '\n');
    while (inFile.get(letter))
    {
      if(letter == '-')
      {
        currentGen[r][c++] = false;
      }
      else if(tolower(letter) == 'x')
      {
        currentGen[r][c++] = true;
      }
      else if(letter == '\n')
      {
        r++;
        c = 0;
      }
    }
  }

  inFile.close();
}

int Game::getGenNum()
{
  return genNum;
}

bool Game::isEmpty()
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if(currentGen[i][j])
      {
        return false;
      }
    }
  }

  return true;
}

bool Game::isStable()
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if(currentGen[i][j] != nextGen[i][j])
      {
        return false;
      }
    }
  }

  return true;
}
