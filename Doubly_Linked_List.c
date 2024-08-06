#include <stdio.h>

struct Node
{
  struct Node *prev;
  struct Node *next;

  int value;
};

int menu(struct Node *hook);
void addNode(struct Node *hook, int value);
void deleteNode(struct Node *hook, int value);
void showNodes(struct Node *hook);
void sortNodes(struct Node *hook);
void memFree(struct Node *hook);

int main()
{
  struct Node *hook = (struct Node *)malloc(sizeof(struct Node));
  hook->value = 0;

  int exit = 0;
  while (exit != 1)
  {
    int exit = menu(hook);
  }

  return 0;
}

int menu(struct Node *hook)
{
  int choice;

  printf("1. Add node\n2. Delete node\n3. Show nodes\n4. Sort\n5. Exit");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    int value;

    printf("Enter new node value: ");
    scanf("%d", &value);

    addNode(hook, value);
    break;
  case 2:
    int value;

    printf("Enter value of a node You want to delete: ");
    scanf("%d", &value);

    deleteNode(hook, value);
    break;
  case 3:
    showNodes(hook);
    break;
  case 4:
    sortNodes(hook);
    break;
  case 5:
    return 1;
    break;
  }

  return 0;
}

void addNode(struct Node *hook, int value)
{
  struct Node *lastNode = hook;

  while (lastNode->next != NULL)
  {
    lastNode = lastNode->next;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  lastNode->next = newNode;
  newNode->prev = lastNode;
  newNode->value = value;
}

void deleteNode(struct Node *hook, int value) // dopatrzec scenariusz usuniuecia hooka
{
  struct Node *tempNode = hook;

  while (tempNode->value != value)
  {
    if (tempNode->next == NULL)
    {
      printf("Node not found.");
      break;
    }
    tempNode = tempNode->next;
  }

  struct Node *prevNode = tempNode->prev;
  struct Node *nextNode = tempNode->next;

  free(tempNode);

  prevNode->next = nextNode;
  nextNode->prev = prevNode;
}

void showNodes(struct Node *hook)
{
  struct Node *tempNode = hook;

  int counter = 0;
  while (tempNode->next != NULL) // ta petla jest do dopatrzenia
  {
    printf("%d: node value - %d\n", counter, tempNode->value);

    tempNode = tempNode->next;
    counter++;
  }
}

void sortNodes(struct Node *hook)
{
}

void memFree(struct Node *hook)
{
  struct Node *tempNode = hook;
  struct Node *nextNode = tempNode->next;

  while (tempNode->next != NULL) // ta petla jest do doptarzenia
  {
    free(tempNode);
    tempNode = nextNode;
    nextNode = tempNode->next;
  }
}