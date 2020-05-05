#include <iostream>
#include <string>
using namespace std;

struct Hero {
  string name;
  string title;
  unsigned int age;
  string weapon;
};

int main() {
  Hero my_hero;
  cout << "What is your hero's name: ";
  cin >> my_hero.name;
  cout << "What is your hero's title: ";
  cin >> my_hero.title;
  cout << "What is your hero's age: ";
  cin >> my_hero.age;
  cout << "What is your hero's weapon of choice: ";
  cin >> my_hero.weapon;
  return 0;
}
