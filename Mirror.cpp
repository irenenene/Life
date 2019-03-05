#include "Mirror.h"
#include <iostream>

using namespace std;

Mirror::Mirror() : Game()
{

}

Mirror::Mirror(int r, int c) : Game(r, c)
{

}

Mirror::~Mirror()
{

}

void Mirror::calcNeighbor()
{
  genNum++;
  
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

int Mirror::northWrap(int rowNum)
{
  if(rowNum == 0)
    return(rowNum);
  else
    return(rowNum-1);
}

int Mirror::eastWrap(int colNum)
{
  if(colNum == columns-1)
    return(colNum);
  else
    return(colNum+1);
}

int Mirror::southWrap(int rowNum)
{
  if(rowNum == rows-1)
    return(rowNum);
  else
    return(rowNum+1);
}

int Mirror::westWrap(int colNum)
{
  if(colNum == 0)
    return(colNum);
  else
    return(colNum-1);
}

int Mirror::north(int rowNum, int colNum)
{
  return(currentGen[northWrap(rowNum)][colNum]);
}

int Mirror::northeast(int rowNum, int colNum)
{
  return(currentGen[northWrap(rowNum)][eastWrap(colNum)]);
}

int Mirror::east(int rowNum, int colNum)
{
  return(currentGen[rowNum][eastWrap(colNum)]);
}

int Mirror::southeast(int rowNum, int colNum)
{
  return(currentGen[southWrap(rowNum)][eastWrap(colNum)]);
}

int Mirror::south(int rowNum, int colNum)
{
  return(currentGen[southWrap(rowNum)][colNum]);
}

int Mirror::southwest(int rowNum, int colNum)
{
  return(currentGen[southWrap(rowNum)][westWrap(colNum)]);
}

int Mirror::west(int rowNum, int colNum)
{
  return(currentGen[rowNum][westWrap(colNum)]);
}

int Mirror::northwest(int rowNum, int colNum)
{
  return(currentGen[northWrap(rowNum)][westWrap(colNum)]);
}
