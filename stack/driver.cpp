#include "./stack.h"
#include<iostream>

using namespace std;

int main() {
  Stack<int> s;
  Stack<int> t(s);

  s.push(1);
  s.push(2);
  s.push(3);

  s.display();
  cout << endl;
  int i = s.pop();

  cout << i << endl;
  s.display();

  cout << endl;
  cout << s.isEmpty() << endl;

  s.pop();

  cout << s.isEmpty() << endl;

  s.pop();
  cout << s.isEmpty() << endl;


  for(int i = 0; i < 100; i++)
    s.push(i);

  s.display();

  for(int i = 0; i < 100; i++)
    s.pop();

  s.display();
}
