#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node* nodeConstructor(int data) {
  Node* single;
  single = (struct Node*)malloc(sizeof(struct Node));
  single->data = data;
  single->next = NULL;
  return single;
};

Node* append(Node* head, int newData) {
  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = (Node*)malloc(sizeof(Node));
  temp->next->data = newData;
  temp->next->next = NULL;
  return temp->next;
};

void traverse(Node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
};

void nodeDestructor(Node* head) {
  while (head->next != NULL) *head = (*head->next);
}