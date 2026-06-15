#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ---------------------------------------------
// Helper function for validated non-negative input
// ---------------------------------------------
double getPositiveInput(const string& prompt)
{
  double value;
  cout << prompt;

  while (!(cin >> value) || value < 0)
  {
    cout << "Invalid Input! Please enter a non-negative number: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  return value;
}

// ---------------------------------------------
// Pause function: waits for ENTER
// ---------------------------------------------
void pressEnter ()
{
  cout << "Press Enter to return to menu...";
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover input
  cin.get(); // wait for ENTER
  cout << endl;
}

// ---------------------------------------------
// Conversion functions
// ---------------------------------------------
void secondsToHours()
{
  double seconds = getPositiveInput("Enter time in seconds: ");
  cout << seconds << " seconds = " << seconds / 3600 << " hours.\n\n";
  pressEnter();
}

void secondsToMinutes()
{
  double seconds = getPositiveInput("Enter time in seconds: ");
  cout << seconds << " seconds = " << seconds / 60 << " minutes.\n\n";
  pressEnter();
}

void minutesToHours()
{
  double minutes = getPositiveInput("Enter time in minutes: ");
  cout << minutes << " minutes = " << minutes / 60 << " hours.\n\n";
  pressEnter();
}

void minutesToSeconds()
{
  double minutes = getPositiveInput("Enter time in minutes: ");
  cout << minutes << " minutes = " << minutes * 60 << " seconds.\n\n";
  pressEnter();
}

void hoursToSeconds()
{
  double hours = getPositiveInput("Enter time in hours: ");
  cout << hours << " hours = " << hours * 3600 << " seconds.\n\n";
  pressEnter();
}

void hoursToMinutes()
{
  double hours = getPositiveInput("Enter time in hours: ");
  cout << hours << " hours = " << hours * 60 << " minutes.\n\n";
  pressEnter();
}

// ---------------------------------------------
// Main program
// ---------------------------------------------
int main ()
{
  int choice;
  char exitChoice = 'n';

  cout << "Welcome to the calculator! " << endl << endl;

  while (exitChoice != 'y' && exitChoice !='Y')
  {
    cout << endl << "Menu: " << endl;
    cout << "1. Convert seconds to hours" << endl;
    cout << "2. Convert seconds to minutes" << endl;
    cout << "3. Convert minutes to hours" << endl;
    cout << "4. Convert minutes to seconds" << endl;
    cout << "5. Convert hours to seconds" << endl;
    cout << "6. Convert hours to minutes" << endl;
    cout << "7. Exit the program." << endl << endl;
    cout << "Please select an option: " << "  ";

    // Validate menu input
        if (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number from 1–7.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline

    switch(choice)
    {
      case 1: secondsToHours(); cout << "Returning to menu...\n\n"; break;

      case 2: secondsToMinutes(); cout << "Returning to menu...\n\n"; break;

      case 3: minutesToHours(); cout << "Returning to menu...\n\n"; break;

      case 4: minutesToSeconds(); cout << "Returning to menu...\n\n"; break;

      case 5: hoursToSeconds(); cout << "Returning to menu...\n\n"; break;

      case 6: hoursToMinutes(); cout << "Returning to menu...\n\n"; break;

      case 7: cout << "Are you sure you want to exit? (y/n): ";
              cin >> exitChoice;
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cout << "\n";
              continue;
      default:
              cout << "Invalid option, please choose from 1 - 7. \n";
              break;
    }
  }
  cout << "Goodbye!\n";
  return 0;
}
