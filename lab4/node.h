typedef struct Node {
  int data;
  struct Node* next;
} Node;
Node* nodeConstructor(int value);
Node* append(Node* head, int newValue);
void traverse(Node* head);
void nodeDestructor(Node* head);