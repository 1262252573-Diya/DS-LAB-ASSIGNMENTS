#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int regNo;
    char name[50];
    struct Node *next;
};

struct Node *head = 0;

void add_student()
{
    struct Node *newnode, *temp;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Registration Number: ");
    scanf("%d", &newnode->regNo);
    printf("Enter Student Name: ");
    scanf("%s", newnode->name);
    newnode->next = 0;

    if (head == 0)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Student registered successfully.\n");
}

void remove_student()
{
    struct Node *temp, *previous;
    int target;

    if (head == 0)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter Registration Number to remove: ");
    scanf("%d", &target);

    temp = head;
    previous = 0;
    while (temp != 0 && temp->regNo != target)
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == 0)
    {
        printf("Student not found.\n");
    }
    else
    {
        previous->next = temp->next;
        free(temp);
        printf("Student record deleted successfully.\n");
    }
}

void display()
{
    struct Node *temp;
    if (head == 0)
    {
        printf("No students registered.\n");
        return;
    }

    temp = head;
    printf("\n     Registered Students     \n");
    while (temp != 0)
    {
        printf("Reg No: %d | Name: %s\n", temp->regNo, temp->name);
        temp = temp->next;
    }
}

void count_participants()
{
    struct Node *temp;
    int count = 0;

    temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    printf("Total registered students: %d\n", count);
}

void sort_list()
{
    struct Node *currnode, *nextnode;
    int tempReg;
    char tempName[50];

    if (head == 0 || head->next == 0)
    {
        printf("List is already sorted or empty.\n");
        return;
    }

    currnode = head;
    while (currnode->next != 0)
    {
        nextnode = currnode->next;
        while (nextnode != 0)
        {
            if (currnode->regNo > nextnode->regNo)
            {
                tempReg = currnode->regNo;
                currnode->regNo = nextnode->regNo;
                nextnode->regNo = tempReg;

                strcpy(tempName, currnode->name);
                strcpy(currnode->name, nextnode->name);
                strcpy(nextnode->name, tempName);
            }
            nextnode = nextnode->next;
        }
        currnode = currnode->next;
    }
    printf("List sorted in ascending order of Registration Number.\n");
}

void reverse_list()
{
    struct Node *prevnode, *current, *nextnode;
    prevnode = 0;
    current = head;

    while (current != 0)
    {
        nextnode = current->next;
        current->next = prevnode;
        prevnode = current;
        current = nextnode;
    }
    head = prevnode;
    printf("List reversed successfully.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("1. Add a Student\n");
        printf("2. Remove a Student\n");
        printf("3. Display the List\n");
        printf("4. Count Total Participants\n");
        printf("5. Sort Lists\n");
        printf("6. Reverse the List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                add_student();
                break;
            }
            case 2:
            {
                remove_student();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                count_participants();
                break;
            }
            case 5:
            {
                sort_list();
                break;
            }
            case 6:
            {
                reverse_list();
                break;
            }
            case 7:
            {
                printf("Exiting program.\n");
                exit(0);
            }
            default:
            {
                printf("Invalid choice! Try again.\n");
                break;
            }
        }
    }
    return 0;
}