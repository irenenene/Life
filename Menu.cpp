#include "Menu.h"
#include <sstream>
#include <fstream>
#include <unistd.h>

using namespace std;

Menu::Menu()
{
  rows = 0;
  columns = 0;
  density = 0.0;
  sim = NULL;
  fileString = "";
}

Menu::~Menu()
{
  cout << "Deleting game object" << endl;
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
      fromFile();
      setBoundary();
      sim->populate(fileString);
    }
    else if (userInput == "2")
    {
      validInput = true;
      fromRandom();
      setBoundary();
      sim->populate(density);
    }
    else if (userInput == "3")
    {
      validInput = true;
      exit(0);
    }
    else
    {
      cout << "Invalid choice. " << endl;
    }
  }

  setOutputType();
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

/*
precondition: row and column needs to be set
postcondition: sim will be pointing to a new subclass of Game
*/
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
      sim = new Classic(rows, columns);
    }
    else if (input == "2")
    {
      isValid = true;
      sim = new Donut(rows, columns);
    }
    else if (input == "3")
    {
      isValid = true;
      sim = new Mirror(rows, columns);
    }
    else
    {
      cout << "Invalid number. " << endl;
    }
  }
}

void Menu::runWithPause()
{
  while(!sim->isEmpty() && !sim->isStable() && (sim->getGenNum() < ITERATIONS))
  {
    cout << sim->toString();
    sim->calcNeighbor();
    sim->update();
    usleep(MILLISECONDS * 1000);
  }
}

void Menu::runWithEnter()
{
  while(!sim->isEmpty() && !sim->isStable() && (sim->getGenNum() < ITERATIONS))
  {
    cout << sim->toString();
    sim->calcNeighbor();
    sim->update();
    getchar();
  }
}

void Menu::outToFile()
{
  cout << "Enter a filename:";
  getline(cin, fileString);

  ofstream outFile;
  outFile.open(fileString);

  if(outFile)
  {
    while(!sim->isEmpty() && !sim->isStable() && (sim->getGenNum() < ITERATIONS))
    {
      outFile << sim->toString();
      sim->calcNeighbor();
      sim->update();
    }
  }
  else
  {
    cout << "error writing to file." << endl;
  }
  outFile.close();
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
      runWithPause();
      isValid = true;
    }
    else if (userInput == "2")
    {
      runWithEnter();
      isValid = true;
    }
    else if (userInput == "3")
    {
      outToFile();
      isValid = true;
    }
    else
    {
      cout << "Invalid choice." << endl;
    }
  }
}

//sets rows, columns, and population density
//only used when user creates a new random assignment
void Menu::fromRandom()
{
  cout << "-Random Assignment-" << endl;
  cout << "Enter the number of rows: ";
  setParameter(&rows);
  cout << "Enter the number of columns: ";
  setParameter(&columns);
  setDensity();
}

//sets rows and columns from a user-specified file
//only used when user starts with map file
//postcondition: fileString is set
void Menu::fromFile()
{
  ifstream inFile;

  cout << "-Map File-" << endl;
  cout << "Please enter a filename: ";
  getline(cin, fileString);
  inFile.open(fileString);

  if(!inFile)
  {
    cout << "Error finding file. " << endl;
    exit(0);
  }
  else
  {
    inFile >> rows;
    inFile.ignore(MAX_LINE, '\n');

    inFile >> columns;
    inFile.ignore(MAX_LINE, '\n');

    inFile.close();
  }
}
