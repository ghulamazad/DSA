#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL, *temp;

// START FUNCTION DECLARATION
int takeIntInput(char *);
void display();
int count();
void insertAtHead(int data);
void insertAtTail(int);
void insertAtPosition(int, int);
void deleteFirst();
void deleteLast();
void deleteNode(int);
// END FUNCTION DECLARATION

void main()
{
    int choice, val, posi;
    do
    {
        printf("\n=====================================\n");
        printf("|               M E N U             |\n");
        printf("=====================================\n");
        printf("1  => Display List.\n");
        printf("2  => Insert at beginning.\n");
        printf("3  => Insert at the end.\n");
        printf("4  => Insert at specific position.\n");
        printf("5  => Delete first Node.\n");
        printf("6  => Delete last Node.\n");
        printf("7  => Delete any Node.\n");
        printf("8  => Count Nodes.\n");
        printf("0  => EXIT.\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            val = takeIntInput("Enter value: ");
            insertAtHead(val);
            break;
        case 3:
            val = takeIntInput("Enter value: ");
            insertAtTail(val);
            break;
        case 4:
            posi = takeIntInput("Enter position to insert the node: ");
            val = takeIntInput("Enter value: ");
            insertAtPosition(posi, val);
            break;
        case 5:
            deleteFirst();
            printf("\nNode deleted successfully\n");
            break;
        case 6:
            deleteLast();
            printf("\nNode deleted successfully\n");
            break;
        case 7:
            posi = takeIntInput("Enter position to delete the node: ");
            deleteNode(posi);
            printf("\nNode deleted successfully\n");
            break;
        case 8:
            val = count();
            printf("\n\nTotal nodes are: %d", val);
            break;
        case 0:
            return;
        default:
            printf("\nInvalid choice\n");
        }
        printf("\n\nPress any key to continuee...");
        getch();
    } while (choice != 0);
}

int takeIntInput(char *msg)
{
    int val;
    printf(msg);
    scanf("%d", &val);
    return val;
}

// traversing a linked list
void display()
{
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// count the Linked List Elements
int count()
{
    int c = 0;
    temp = head;

    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    return c;
}

void insertAtHead(int data)
{
    if (head == NULL)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        head = temp;
        tail = temp;
    }
    else
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(int data)
{
    if (tail == NULL)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        tail = temp;
        head = temp;
    }
    else
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(int position, int data)
{
    // inserting at first position
    if (position == 1)
    {
        insertAtHead(data);
        return;
    }

    temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(data);
        return;
    }

    // creating a node for d
    struct Node *nodeToInsert = (struct Node *)malloc(sizeof(struct Node));
    nodeToInsert->data = data;

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }
    temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    free(temp);
}

void deleteLast()
{
    if (tail == NULL)
    {
        printf("List is empty.");
        return;
    }

    temp = tail;
    tail = tail->prev;
    temp->prev = NULL;
    tail->next = NULL;
    free(temp);
}

void deleteNode(int position)
{
    // deleting first node
    if (position == 1)
        deleteFirst();
    else if (position == count())
        deleteLast();
    else
    {
        // deleting any middle node
        struct Node *curr = head;
        struct Node *prev = NULL;
        int c = 1;
        while (c < position)
        {
            prev = curr;
            curr = curr->next;
            c++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
    }
}
