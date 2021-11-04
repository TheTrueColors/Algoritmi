#ifndef Paziente_H
#define Paziente_H

#include <iostream>

using namespace std;

class Paziente {
 private:
  string name;
  string surname;
  int age;
  int priority;

 public:
  Paziente(string name, string surname, int age, int priority) {
    this->name = name;
    this->surname = surname;
    this->age = age;
    this->priority = priority;
  }

  void changePriority(short newPriority) { this->priority = newPriority; }
  int getPriority() { return priority; }
  int getAge() { return age; }
  string getName() { return name; }
  string getSurname() { return surname; }

  friend ostream& operator<<(ostream& os, Paziente& p) {
    cout << "Name: " << p.name << " Surname: " << p.surname << " Age: " << p.age
         << " ";
    if (p.priority == 1)
      cout << "Priority: Red" << endl;
    else if (p.priority = 2)
      cout << "Priority: Orange" << endl;
    else if (p.priority == 3)
      cout << "Priority: Green" << endl;

    return os;
  }
};

#endif