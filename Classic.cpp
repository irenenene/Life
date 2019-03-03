#include "Classic.h"
#include <iostream>

using namespace std;

Classic::Classic() : Game()
{
  //cout << "called default";
}

Classic::Classic(int r, int c) : Game(r, c)
{
  //cout << "called with args";
}

Classic::~Classic()
{
  //base class destructor is automatically invoked
}

void Classic::calcNeighbor()
{
  //cout << "Classic->calcNeighbor" << endl;
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

int Classic::north(int rowNum, int colNum)
{
  if(rowNum == 0)
    return 0;
  else
    return(currentGen[rowNum-1][colNum]); //implicit bool to int, yay
}

int Classic::northeast(int rowNum, int colNum)
{
  if((rowNum == 0) || (colNum == columns-1))
    return 0;
  else
    return(currentGen[rowNum-1][colNum+1]);
}

int Classic::east(int rowNum, int colNum)
{
  if(colNum == columns-1)
    return 0;
  else
    return(currentGen[rowNum][colNum+1]);
}

int Classic::southeast(int rowNum, int colNum)
{
  if((rowNum == rows-1) || (colNum == columns-1))
    return 0;
  else
    return(currentGen[rowNum+1][colNum+1]);
}

int Classic::south(int rowNum, int colNum)
{
  if(rowNum == rows-1)
    return 0;
  else
    return(currentGen[rowNum+1][colNum]);
}

int Classic::southwest(int rowNum, int colNum)
{
  if((rowNum == rows-1) || (colNum == 0))
    return 0;
  else
    return(currentGen[rowNum+1][colNum-1]);
}

int Classic::west(int rowNum, int colNum)
{
  if(colNum == 0)
    return 0;
  else
    return(currentGen[rowNum][colNum-1]);
}

int Classic::northwest(int rowNum, int colNum)
{
  if((rowNum == 0) || (colNum == 0))
    return 0;
  else
    return(currentGen[rowNum-1][colNum-1]);
}
