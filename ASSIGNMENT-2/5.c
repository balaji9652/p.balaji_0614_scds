/*Q5: Circular Queue Basic Operations
Write a C program to implement a Circular Queue using an array.
The program should support the following operations:
• Enqueue – Insert an element into the circular queue.
• Dequeue – Remove an element from the circular queue.
• Peek – Display the front element of the queue without removing it.
• Display – Show all elements currently present in the queue.
The program should be menu driven so that the user can select and perform different
operations on the circular queue.*/

/*Algorithm
1)Start
2)Initialize front = rear = -1
3)For Enqueue:
     Check overflow → (rear + 1) % MAX == front
     Insert element and update rear
4)For Dequeue:
     Check underflow → queue empty
     Remove element and update front
5)For Peek:
    Display front element
6)For Display:
    Traverse from front to rear circularly
7)Repeat using menu until exit
8)Stop
*/


#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;

    printf("Inserted: %d\n", value);
}

// Dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Peek
void peek() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Display
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    int i = front;
    printf("Queue elements:\n");

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}