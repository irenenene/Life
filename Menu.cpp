#include "Menu.h"
#include <sstream>

using namespace std;

Menu::Menu()
{
  rows = 0;
  columns = 0;
  density = 0.0;
  boundary = "";
  outputType = "";
  sim = NULL;
}

Menu::~Menu()
{
  cout << "No news is good news." << endl;
  delete sim;
}

void Menu::initialize()
{
  bool validInput = false;
  string userInput = "";

  while (!validInput)
  {
    cout << "-Startup-" << endl;
    cout << "1. Provide map file" << endl;
    cout << "2. Random assignment" << endl;
    cout << "3. Exit" << endl;
    cout << "Please enter a number corresponding to your choice: ";
    getline(cin, userInput);

    if (userInput == "1")
    {
      validInput = true;
    }
    else if (userInput == "2")
    {
      validInput = true;
      fromRandom();
      sim->calcNeighbor();
    }
    else if (userInput == "3")
    {
      validInput = true;
      //add some exit code
    }
    else
    {
      cout << "Invalid choice. " << endl;
    }
  }
}

void Menu::setParameter(int* value)
{
  string input;
  bool success = false;

  while (!success)
  {
    stringstream convertor;

    getline(cin, input);
    convertor << input;
    convertor >> *value;
    if(convertor.fail())
    {
      cout << "Invalid input. Please enter an integer." << endl;
    }
    else
    {
      success = true;
    }
  }
}

void Menu::setDensity()
{
  string input;
  bool success = false;

  cout << "Enter the initial population density (Greater than 0 but less than 1): ";

  while (!success)
  {
    stringstream convertor;

    getline(cin, input);
    convertor << input;
    convertor >> density;
    if(convertor.fail())
    {
      cout << "You did not enter a number." << endl;
    }
    else
    {
      if ((density > 0) && (density <= 1))
        success = true;
      else
        cout << "You need to enter a value >0 and <= 1." << endl;
    }
  }
}

void Menu::setBoundary()
{
  string input;
  bool isValid = false;

  cout << "-Boundary types-" << endl;
  cout << "1. Classic" << endl;
  cout << "2. Doughnut" << endl;
  cout << "3. Mirror" << endl;

  while (!isValid)
  {
    cout << "Please enter a number corresponding to your choice: ";
    getline(cin, input);

    if (input == "1")
    {
      isValid = true;
      boundary = "classic";
    }
    else if (input == "2")
    {
      isValid = true;
      boundary = "doughnut";
    }
    else if (input == "3")
    {
      isValid = true;
      boundary = "mirror";
    }
    else
    {
      cout << "Invalid number. " << endl;
    }
  }
}

void Menu::printResults()
{
  //testing
  cout << "Rows: " << rows << endl;
  cout << "Columns: " << columns << endl;
  cout << "Density: " << density << endl;
  cout << boundary << endl;
  cout << outputType << endl;
  if (sim != NULL)
    cout << sim->toString();
    cout << "Next Generation: " << endl;
    cout << sim->toStringNext();
}

void Menu::setOutputType()
{
  bool isValid = false;
  string userInput = "";

  cout << "-Output Type-" << endl;
  cout << "1. Brief pause between generations. " << endl;
  cout << "2. Press \"enter\" between generations." << endl;
  cout << "3. Output all results to a file. " << endl;

  while (!isValid)
  {
    cout << "Enter the number corresponding to the output type you want: ";
    getline(cin, userInput);

    if (userInput == "1")
    {
      outputType = "pause";
      isValid = true;
    }
    else if (userInput == "2")
    {
      outputType = "enter";
      isValid = true;
    }
    else if (userInput == "3")
    {
      outputType = "file";
      isValid = true;
    }
    else
    {
      cout << "Invalid choice." << endl;
    }
  }
}

void Menu::fromRandom()
{
  cout << "-Random Assignment-" << endl;
  cout << "Enter the number of rows: ";
  setParameter(&rows);
  cout << "Enter the number of columns: ";
  setParameter(&columns);
  setDensity();

  //creates a new map from scratch - CHANGE GAME TYPE TO SUBTYPE RANDOM ONCE DEFINED
  //sim = new Game(rows, columns);
  //******************CREATE NEW INSTANCE OF CLASSIC HERE *********************
  sim = new Classic(rows, columns);
  //***************************************************************************
  setBoundary();
  sim->populate(density);
}

int Menu::getRows()
{
  return rows;
}

int Menu::getColumns()
{
  return columns;
}

float Menu::getDensity()
{
  return density;
}

string Menu::getBoundary()
{
  return boundary;
}

string Menu::getOutputType()
{
  return outputType;
}
