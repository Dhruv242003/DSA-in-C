#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item) {
  int i;
  if (rear == MAX_SIZE - 1) {
    printf("Queue overflow\n");
    return;
  }


  if (front == -1) {
    front = 0;
    rear = 0;
    queue[rear] = item;
    return;
  }


  for (i = rear; i >= front; i--) {
    if (item > queue[i]) {
      queue[i+1] = queue[i];
    }
    else {
      break;
    }
  }
  queue[i+1] = item;
  rear++;
}



int dequeue() {
  int item;
  if (front == -1 || front > rear) {
    printf("Queue underflow\n");
    return -1;
  }
  item = queue[front];
  front++;
  return item;
}

void display() {
  int i;
  if (front == -1 || front > rear) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements are:\n");
  for (i = front; i <= rear; i++) {
    printf("%d\n", queue[i]);
  }
}

int main() {
  int choice, item;
  do {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the item to be enqueued: ");
        scanf("%d", &item);
        enqueue(item);
        break;
      case 2:
        item = dequeue();
        if (item != -1) {
          printf("Dequeued item is: %d\n", item);
        }
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Exiting from the program\n");
        break;
      default:
        printf("Invalid choice, please try again\n");
    }
  } while (choice != 4);
  return 0;
}