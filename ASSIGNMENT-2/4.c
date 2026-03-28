/*Q4: Printer Queue Simulation
Write a C program to simulate a printer queue system using queue operations.
Operations to support:
• Add document to queue
• Print document
• Display pending documents*/


/*Algorithm
1)Start
2)Initialize queue (front = rear = -1)
3)Repeat menu:
     Insert document (enqueue)
     Print document (dequeue)
     Display queue
4)Handle overflow and underflow conditions
5)Stop
*/


#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][50];  // Queue to store document names
int front = -1, rear = -1;

// Enqueue operation
void enqueue(char doc[]) {
    if (rear == MAX - 1) {
        printf("Queue Overflow (Printer Queue Full)\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    strcpy(queue[rear], doc);
    printf("Document added to queue\n");
}

// Dequeue operation
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow (No documents to print)\n");
        return;
    }

    printf("Printing document: %s\n", queue[front]);
    front++;
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        printf("No pending documents\n");
        return;
    }

    printf("Pending documents:\n");
    for (int i = front; i <= rear; i++) {
        printf("%s\n", queue[i]);
    }
}

int main() {
    int choice;
    char doc[50];

    do {
        printf("\n--- Printer Queue Menu ---\n");
        printf("1. Add Document\n");
        printf("2. Print Document\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter document name: ");
                scanf("%s", doc);
                enqueue(doc);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}