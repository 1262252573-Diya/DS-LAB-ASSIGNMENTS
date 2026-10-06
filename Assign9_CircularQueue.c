    #include <stdio.h>
    #include <string.h>

    #define N 5

    struct Job 
    {
        int jobID;
        char docTitle[100];
    };

    struct Job queue[N];
    int front = -1;
    int rear = -1;

    int isFull()
    {
        if ((rear + 1) % N == front)
        {
            return 1;
        }
        return 0;
    }

    int isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return 1;
        }
        return 0;
    }

    void enqueue(int id, char title[]) 
    {
        if (isFull()) 
        {
            printf("Queue is full\n");
            return;
        }

        if (front == -1) 
        {
            front = rear = 0;
        } 
        else 
        {
            rear = (rear + 1) % N;
        }

        queue[rear].jobID = id;
        strcpy(queue[rear].docTitle, title);
        printf("Job Added: ID : %d  Title: %s\n", id, title);
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            printf("Queue is empty\n");
            return;
        }

        printf("Processing Job: ID: %d   Title: %s\n", queue[front].jobID, queue[front].docTitle);

        if (front == rear) 
        {
            front = rear = -1;
        } 
        else 
        {
            front = (front + 1) % N;
        }
    }

    void display() 
    {
        if (isEmpty()) 
        {
            printf("Queue is empty\n");
            return;
        }

        printf("Current Print Queue:\n");
        int i = front;
        while (1) 
        {
            printf("Job ID: %d, Title: %s\n", queue[i].jobID, queue[i].docTitle);
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % N;
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
                if (isFull())
                {
                    printf("Queue is full\n");
                }
                else
                {
                    char input[100];
                    printf("Enter The %d title: ", n);
                    scanf(" %[^\n]", input);
                    enqueue(n, input);
                    n++;
                }
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