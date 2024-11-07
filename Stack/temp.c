#include <stdio.h>
#include <stdlib.h>
#define max 100
int stack[max];
int top = -1;
void push(int data) {
  if (top == max - 1) {
    printf("Overflow");
    return;
  } else {
    stack[++top] = data;
  }
}
int pop() {
  if (top == -1) {
    printf("Underflow");
    return (-999);
  } else {
    int value = stack[top--];
    return (value);
  }
}
int is_Empty() {
  if (top == -1) {
    return 1;
  }
  return 0;
}
int is_Full() {
  if (top == max - 1) {
    return 1;
  }
  return 0;
}
void traverse() {
  if (top == -1) {
    return;
  } else {
    int x = pop();
    traverse();
    printf("%d", x);
    push(x);
  }
}
int main() {
  int n, ele, choice;
  printf("Enter the number of elements:");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Element %d:", i + 1);
    scanf("%d", &ele);
    push(ele);
  }
  while (1) {
    printf("\nEnter "
           "choice:\n1.Push\n2.Pop\n3.IsEmpty\n4.IsFull\n5.Traverse\n6.Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the element to be pushed:");
      scanf("%d", &ele);
      push(ele);
      break;
    case 2:
      ele = pop();
      printf("Popped element is %d", ele);
      break;
    case 3:
      if (is_Empty())
        return 1;
      return 0;
      break;
    case 4:
      if (is_Full())
        return 1;
      return 0;
      break;
    case 5:
      printf("Traverse:\n");
      traverse();
      break;
    case 6:
      exit(0);
      break;
    default:
      printf("Invalid choice");
      break;
    }
  }
}