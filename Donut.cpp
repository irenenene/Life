#include "Donut.h"
#include <iostream>

using namespace std;

Donut::Donut() : Game()
{

}

Donut::Donut(int r, int c) : Game(r, c)
{

}

Donut::~Donut()
{

}

void Donut::calcNeighbor()
{
  cout << "Donut->calcNeighbor" << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      int neighbors = north(i, j) + northeast(i, j) + east(i, j) + southeast(i, j) +
                      south(i, j) + southwest(i, j) + west(i, j) + northwest(i,j);

      if (currentGen[i][j])
      {
        if ((neighbors == 2) || (neighbors == 3))
        {
          nextGen[i][j] = true;
        }
        else
        {
          nextGen[i][j] = false;
        }
      }
      else
      {
        if(neighbors == 3)
        {
          nextGen[i][j] = true;
        }
        else
        {
          nextGen[i][j] = false;
        }
      }
    }
  }
}

int Donut::northWrap(int rowNum)
{
  if(rowNum == 0)
    return(rows-1);
  else
    return(rowNum-1);
}

int Donut::eastWrap(int colNum)
{
  if(colNum == columns-1)
    return(0);
  else
    return(colNum+1);
}

int Donut::southWrap(int rowNum)
{
  if(rowNum == rows-1)
    return(0);
  else
    return(rowNum+1);
}

int Donut::westWrap(int colNum)
{
  if(colNum == 0)
    return(columns-1);
  else
    return(colNum-1);
}

int Donut::north(int rowNum, int colNum)
{
  return(currentGen[northWrap(rowNum)][colNum]);
}

int Donut::northeast(int rowNum, int colNum)
{
  return(currentGen[northWrap(rowNum)][eastWrap(colNum)]);
}

int Donut::east(int rowNum, int colNum)
{
  return(currentGen[rowNum][eastWrap(colNum)]);
}

int Donut::southeast(int rowNum, int colNum)
{
  return(currentGen[southWrap(rowNum)][eastWrap(colNum)]);
}

int Donut::south(int rowNum, int colNum)
{
  return(currentGen[southWrap(rowNum)][colNum]);
}

int Donut::southwest(int rowNum, int colNum)
{
  return(currentGen[southWrap(rowNum)][westWrap(colNum)]);
}

int Donut::west(int rowNum, int colNum)
{
  return(currentGen[rowNum][westWrap(colNum)]);
}

int Donut::northwest(int rowNum, int colNum)
{
  return(currentGen[northWrap(rowNum)][westWrap(colNum)]);
}
