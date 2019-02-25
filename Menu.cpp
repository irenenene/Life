#include "Menu.h"
#include <sstream>

using namespace std;

Menu::Menu()
{
  exit = false;
  rows = 0;
  columns = 0;
  density = 0.0;
  boundary = "";
}

Menu::~Menu()
{
  cout << "No news is good news." << endl;
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
      cout << "-Random Assignment-" << endl;
      validInput = true;
      cout << "Enter the number of rows: ";
      setParameter(&rows);
      cout << "Enter the number of columns: ";
      setParameter(&columns);
      setDensity();
    }
    else if (userInput == "3")
    {
      validInput = true;
      exit = true;
    }
    else
    {
      cout << "Invalid choice. " << endl;
    }
  }

  setBoundary();
}

void Menu::setParameter(int* value)
{
  string input;
  bool success = false;

  while(!success)
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

  while(!success)
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
      if((density > 0) && (density <= 1))
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

  while(!isValid)
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
}
