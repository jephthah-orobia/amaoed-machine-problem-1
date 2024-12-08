/* ****************************************************************
 * @author: Jephthah M. Orobia
 * @app name: Machine Problem 1
 * @app desc: Show Enrollment Slip
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
  char c;
  string name, course, year_name;
  int year_lvl;
  double n_units, tfee, downpay, balance, rate;

  // INPUT PHASE
  cout << "Student Name: ";
  while(cin >> noskipws >> c){
    if(c == '\n') break;
    name += c;
  }
  cout << "Program/Course: ";
  while(cin >> noskipws >> c){
    if(c == '\n') break;
    course += c;
  }
  
  while(true){
    cout << "Year Level: ";
    cin >> noskipws >> year_lvl;
    if(!cin.fail() && year_lvl > 0 && year_lvl < 6){
      break;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "ERROR: invalid year level. Integers 1 - 5 only!" << endl;
    }
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  while(true){
    cout << "Number of Units Enrolled: ";
    cin >> noskipws >> n_units;
    if(!cin.fail() && n_units > 0){
      break;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "ERROR: invalid number of units!" << endl;
    }
  }


  // CALCULATION PHASE
  switch (year_lvl)
  {
  case 1:
    year_name = "Freshman";
    rate = 1500;
    break;
  
  case 2:
    year_name = "Sophomore";
    rate = 1800;
    break;

  case 3:
    year_name = "Junior";
    rate = 2000;
    break;

  default:
    year_name = "Senior";
    rate = 2300;
    break;
  }

  tfee = n_units * rate;
  downpay = 0.3 * tfee;
  balance = tfee - downpay;

  // OUPUT PHASE

  cout << "\n===========================================================\n\n";
  cout << "\t\tENROLLMENT SLIP" << endl;
  cout << "\tStudent Name\t: " << name << endl;
  cout << "\tProgram/Course\t: " << course << endl;
  cout << "\tYear Name\t: " << year_name << endl;
  cout << "\tNo. of Units\t: " << n_units << endl;
  cout << "\tTuition Fee\t: " << tfee << endl;
  cout << "\tDown Payment\t: " << downpay << endl;
  cout << "\tBalance\t\t: " << balance << endl;
  cout << "\n===========================================================\n\n";

  // EXIT MANAGEMENT
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Enter 'r' to restart or any character to exit: ";
  cin >> c;
  
  if(c == 'r')
  {
    system("cls");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return main();
  } else {
    return EXIT_SUCCESS;
  }
}
