#include <iostream>
#include <string.h>
#include <stdexcept>

using namespace std;

class student {
  public:
    char name[50];
    char surname[50];
    char number[50];
};

student s;

void init() {
  strcpy(s.name, "");
  strcpy(s.surname, "");
  strcpy(s.number, "");
}

bool isString(string str)
{
  for (int i = 0; i < str.length(); i++){
    char x = str.at(i);
    if (int(x) >= 48 && int(x) <= 57)
      return false;
  }
  return true;
}

bool isDigit(string str){
  for (int i = 0; i < str.length(); i++){
    char x = str.at(i);
    if (int(x) > 57)
      return false;
  }
  return true;
}

void enter_name() {
  cout << "Enter name: ";
  cin >> s.name;
  if (!isString(s.name)){
    strcpy(s.name, "");
    throw runtime_error("You use number in name.");
  }
}

void enter_surname() {
  cout << "Enter surname: ";
  cin >> s.surname;
  if (!isString(s.surname)){
    strcpy(s.surname, "");
    throw runtime_error("You use number in surname.");
  }
}

void enter_number() {
  cout << "Enter number: ";
  cin >> s.number;
  if (!isDigit(s.number)){
    strcpy(s.number, "");
    throw runtime_error("You use string in number.");
  }
}

void func() {
  try {
    if (strcmp(s.name, "") == 0)
      enter_name();
    if (strcmp(s.surname, "") == 0)
      enter_surname();
    if (strcmp(s.number, "") == 0)
      enter_number();
  }

  catch (const exception &ex)
  {
    cout << ex.what() << "\n";
    func();
  }
}

int main()
{
    init();
    func();
    cout << s.name << " " << s.surname << " " << s.number;

    return 0;
}
