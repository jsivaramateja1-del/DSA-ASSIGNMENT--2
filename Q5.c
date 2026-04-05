#include <stdio.h>

#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    int full;

    // check circular full condition
    if (rear == MAX - 1)
        full = (front == 0);
    else
        full = (front == rear + 1);

    if (full)
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
        front = 0; // first element

    // circular increment of rear
    if (rear == MAX - 1)
        rear = 0;
    else
        rear = rear + 1;

    queue[rear] = val;
    printf("%d enqueued\n", val);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n"); // empty check
        return;
    }

    printf("%d dequeued\n", queue[front]);

    if (front == rear)
        front = rear = -1; // reset queue
    else if (front == MAX - 1)
        front = 0;
    else
        front = front + 1; // circular increment
}

void peek()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        // circular traversal
        if (i == MAX - 1)
            i = 0;
        else
            i = i + 1;
    }
    printf("\n");
}

int main()
{
    int choice, val;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
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
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}