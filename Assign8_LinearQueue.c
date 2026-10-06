#include <stdio.h>
#include <string.h>

struct Job 
{
    int jobID;
    char docTitle[100];
};

int max = 100;
struct Job queue[100];
int front = -1;
int rear = -1;

void enqueue(int id, char title[]) 
{
    if (rear == max - 1) 
    {
        printf("Printer queue is full!\n");
        return;
    }
    if (front == -1 && rear == -1) 
    { 
        front = rear = 0; 
    }
    else 
    {
        rear++;
    }
    queue[rear].jobID = id;
    strcpy(queue[rear].docTitle, title);
    printf("Job Added: ID : %d  Title: %s\n", id, title);
}

void dequeue() 
{
    if (front == -1 && rear == -1) 
    {
        printf("Printer queue is empty!\n");
        return;
    }
    
    printf("Processing Job: ID: %d   Title: %s\n", queue[front].jobID, queue[front].docTitle);
    
    if (front == rear) 
    {
        front = -1;
        rear = -1;
    } 
    else 
    {
        front++;
    }
}

void display() 
{
    if (front == -1 && rear == -1) 
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current Print Queue:\n");
    for (int i = front; i <= rear; i++) 
    {
        printf("Job ID: %d, Title: %s\n", queue[i].jobID, queue[i].docTitle);
    }
}

int main()
{
    int ch;
    int n = 1;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. To add Elements\n");
        printf("2. To Display current queue\n");
        printf("3. To remove a eleemnt from the Queue\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            char input[50];
            printf("Enter The %d title:", n);
            scanf("%s", input);
            enqueue(n, input);
            n++;
        }
        else if (ch == 2)
        {
            display();
        }
        else if (ch == 3)
        {
            dequeue();
        }
        else if (ch == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice!\n TRY AGAIN! \n");
        }
    }
    printf("Thank You!\n");
    return 0;
}