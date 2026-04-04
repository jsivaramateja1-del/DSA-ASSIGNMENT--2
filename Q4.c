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
        printf("Queue full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    strcpy(queue[rear], doc);
    printf("Document '%s' added to queue\n", doc);
}

void printDocument()
{
    if (front == -1 || front > rear)
    {
        printf("No documents in queue\n");
        return;
    }
    printf("Printing document: '%s'\n", queue[front]);
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void displayPending()
{
    if (front == -1 || front > rear)
    {
        printf("No pending documents\n");
        return;
    }
    printf("Pending documents:\n");
    for (int i = front; i <= rear; i++)
        printf("  %d. %s\n", i - front + 1, queue[i]);
}

int main()
{
    int choice;
    char doc[100];

    while (1)
    {
        printf("\n1. Add document\n");
        printf("2. Print document\n");
        printf("3. Display pending\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                printf("Enter document name: ");
                fgets(doc, 100, stdin);
                doc[strcspn(doc, "\n")] = '\0';
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