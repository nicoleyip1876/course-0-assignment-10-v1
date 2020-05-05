#include <iostream>
#include <string>
using namespace std;

struct Point {
  float x; 
  float y; 
  float z; 
  float w;
};

int main() {
  Point position;
  position.x = .3;
  position.y = .6;
  position.z = 1.6;
  position.w = -.56;
  const float manhattan_distance = position.x + position.y + position.z + position.w;
  cout << "The points manhattan distance is: " << manhattan_distance;
  return 0;
}
