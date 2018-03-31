#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

#define DEFAULT_STACK_CAPACITY 10

template<typename T>
class Stack {
  T *data;
  unsigned int capacity;
  unsigned int size;
  void resize();

public:
  Stack();
  Stack(const Stack &);
  ~Stack();

  void push(const T &);
  T pop();
  const T &top();

  bool isEmpty();

  void display();
};

template<typename T>
void Stack<T>::resize() {
  unsigned int newCapacity =
    static_cast<unsigned int>(static_cast<double>(capacity) * 1.5);

  T *temp = new T[newCapacity];

  for (int i = 0; i < size; i++)
    temp[i] = data[i];

  delete []data;
  data = temp;
  capacity = newCapacity;
}

template<typename T>
Stack<T>::Stack() {
  capacity = DEFAULT_STACK_CAPACITY;
  size = 0;

  data = new T[capacity];
}

template<typename T>
Stack<T>::Stack(const Stack &ref) {
  capacity = ref.capacity;
  size = ref.size;
  data = new T[capacity];

  for(int i = 0; i < size; i++) {
    data[i] = ref.data[i];
  }
}

template<typename T>
Stack<T>::~Stack() {
  if(data) delete[] data;
  data = (T *)0;
  capacity = 0;
  size = 0;
}

template<typename T>
void Stack<T>::push(const T &element) {
  if (size == capacity)
    resize();

  data[size++] = element;
}

template<typename T>
T Stack<T>::pop() {
  if (size == 0) throw new runtime_error("stack is empty.");
  return data[--size];
}

template<typename T>
const T &Stack<T>::top() {
  if (size == 0) throw new runtime_error("stack is empty.");
  return data[size - 1];
}

template<typename T>
bool Stack<T>::isEmpty() {
  return size == 0;
}

template<typename T>
void Stack<T>::display() {
  for(int i = size - 1; i >= 0; i--) cout << data[i];
}

#endif
