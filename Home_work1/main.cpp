/**
 * @file main.cpp
 * @author Steve Gilland (steven.gilland@gmail.com)
 * @brief Linked List Test File
 * @version 0.1
 * @date 2022-01-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

#include "LinkedList.h"

int main() {
  LinkedList<int> intList;

  for (int i = 0; i < 10; i++) intList.add(i);

  intList.add(5);
  intList.add(7);
  intList.add(11);
  intList.add(2);
  intList.remove(5);
  intList.remove(7);
  std::cout << intList;

  return 0;
}