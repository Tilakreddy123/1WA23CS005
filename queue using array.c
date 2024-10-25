#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Element is inserted: %d\n", value);
    }
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
    } else {
        int delete = queue[front];
        front++;
        if (front>rear) {
            front = rear = -1;
        }
        printf("Element is deleted: %d\n", delete);
    }
}
void display() {
    if (front==-1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting....\n");
                return 0;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }
}