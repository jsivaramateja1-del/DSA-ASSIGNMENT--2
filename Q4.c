#include <stdio.h>
#include <string.h>

#define MAX 100
char queue[MAX][100];
int front = -1;
int rear = -1;

void addDocument(char doc[])
{
    if (rear == MAX - 1)
    {
        printf("Queue full\n"); // overflow
        return;
    }
    if (front == -1)
        front = 0; // first element
    strcpy(queue[++rear], doc);
}

void printDocument()
{
    if (front == -1 || front > rear)
    {
        printf("No documents in queue\n"); // empty queue
        return;
    }
    printf("Printing document: '%s'\n", queue[front]);

    if (++front > rear) // move front
        front = rear = -1; // reset queue
}

void displayPending()
{
    if (front == -1 || front > rear)
    {
        printf("No pending documents\n"); // empty
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d. %s\n", i - front + 1, queue[i]); // display queue
}

int main()
{
    int choice;
    char doc[100];

    while (1)
    {
        printf("\n1. Add document\n2. Print document\n3. Display pending\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice)
        {
            case 1:
                printf("Enter document name: ");
                fgets(doc, 100, stdin);
                doc[strcspn(doc, "\n")] = '\0'; // remove newline
                addDocument(doc);
                break;

            case 2:
                printDocument();
                break;

            case 3:
                displayPending();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}