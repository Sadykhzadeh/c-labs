#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main() {
  printf("Create a node with value 1.\n");
  Node* test = nodeConstructor(1);
  printf("First node traverse: ");
  traverse(test);
  printf("\n\nCreate another value via appending the 2 into first node\n");
  Node* secondTest = append(test, 2);
  printf("First node traverse: ");
  traverse(test);
  printf("Second node traverse: ");
  traverse(secondTest);
  printf("\n\nJust puch a value 3 into first node\n");
  append(test, 3);
  printf("First node traverse: ");
  traverse(test);
  printf("Totally cleaned the first node");
  nodeDestructor(test);
  traverse(test);
  return 0;
}