#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

// Function to create a header node for circular linked list
struct Node* createHeader()
{
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->coeff = 0;
    head->exp = -1;
    head->next = head;
    return head;
}

// Function to insert term at the end of the circular linked list
void insertTerm(struct Node *head, int coeff, int exp)
{
    if (coeff == 0)
    {
        return;
    }

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->coeff = coeff;
    newnode->exp = exp;

    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
}

// Function to take input and build the polynomial
void createPolynomial(struct Node *head)
{
    int n, coeff, exp, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);
        insertTerm(head, coeff, exp);
    }
}

// Function to display the polynomial in mathematical notation
void displayPolynomial(struct Node *head)
{
    struct Node *temp = head->next;

    if (temp == head)
    {
        printf("0\n");
        return;
    }

    while (temp != head)
    {
        if (temp->coeff > 0 && temp != head->next)
        {
            printf(" + ");
        }
        else if (temp->coeff < 0 && temp != head->next)
        {
            printf(" - ");
        }
        else if (temp->coeff < 0 && temp == head->next)
        {
            printf("-");
        }

        int absCoeff = abs(temp->coeff);

        if (temp->exp == 0)
        {
            printf("%d", absCoeff);
        }
        else if (temp->exp == 1)
        {
            if (absCoeff == 1)
            {
                printf("x");
            }
            else
            {
                printf("%dx", absCoeff);
            }
        }
        else
        {
            if (absCoeff == 1)
            {
                printf("x^%d", temp->exp);
            }
            else
            {
                printf("%dx^%d", absCoeff, temp->exp);
            }
        }

        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials using header circular linked lists
struct Node* addPolynomial(struct Node *h1, struct Node *h2)
{
    struct Node *h3 = createHeader();
    struct Node *t1 = h1->next;
    struct Node *t2 = h2->next;

    while (t1->exp != -1 || t2->exp != -1)
    {
        if (t1->exp == t2->exp)
        {
            int sum = t1->coeff + t2->coeff;
            if (sum != 0)
            {
                insertTerm(h3, sum, t1->exp);
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->exp > t2->exp)
        {
            insertTerm(h3, t1->coeff, t1->exp);
            t1 = t1->next;
        }
        else
        {
            insertTerm(h3, t2->coeff, t2->exp);
            t2 = t2->next;
        }
    }

    return h3;
}

int main()
{
    struct Node *poly1 = createHeader();
    struct Node *poly2 = createHeader();
    struct Node *poly3 = NULL;
    int choice;

    while (1)
    {
        printf("1. Create Polynomial 1\n");
        printf("2. Create Polynomial 2\n");
        printf("3. Display Polynomial 1\n");
        printf("4. Display Polynomial 2\n");
        printf("5. Add Polynomials\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\n Create Polynomial 1 \n");
                createPolynomial(poly1);
                break;

            case 2:
                printf("\n Create Polynomial 2 \n");
                createPolynomial(poly2);
                break;

            case 3:
                printf("\nPolynomial 1: ");
                displayPolynomial(poly1);
                break;

            case 4:
                printf("\nPolynomial 2: ");
                displayPolynomial(poly2);
                break;

            case 5:
                poly3 = addPolynomial(poly1, poly2);
                printf("\nResultant Polynomial (Sum): ");
                displayPolynomial(poly3);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}