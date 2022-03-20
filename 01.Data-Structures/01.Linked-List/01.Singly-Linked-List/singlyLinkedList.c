#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define false 0
#define true 1

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL, *lastNode = NULL;

// START FUNCTION DECLARATION
int takeIntInput(char *);
void display(struct Node *);
int count(struct Node *);
void insertAtBeg(int data);
void insertAtLast(int);
void insert(struct Node *, int, int);
int search(int);
void deleteFirst();
void deleteLast();
void deleteAt(struct Node *, int);
void update(int);
void reverse();
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
        printf("5  => Insert before a given position.\n");
        printf("6  => Search an element.\n");
        printf("7  => Delete first element.\n");
        printf("8  => Delete last element.\n");
        printf("9  => Delete any element.\n");
        printf("10 => Update a node.\n");
        printf("11 => Reverse the List.\n");
        printf("12 => Count nodes.\n");
        printf("0  => EXIT.\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(head);
            break;
        case 2:
            val = takeIntInput("Enter value: ");
            insertAtBeg(val);
            break;
        case 3:
            val = takeIntInput("Enter value: ");
            insertAtLast(val);
            break;
        case 4:
            posi = takeIntInput("Enter position to insert the node: ");
            val = takeIntInput("Enter value: ");
            insert(head, posi, val);
            break;
        case 5:
            posi = takeIntInput("Enter position to insert the node: ");
            val = takeIntInput("Enter value: ");
            insert(head, posi - 1, val);
            break;
        case 6:
            val = takeIntInput("Enter value for searching: ");
            if (search(val))
            {
                printf("%d is found.", val);
            }
            else
            {
                printf("%d does not exist", val);
            }
            break;
        case 7:
            deleteFirst();
            break;
        case 8:
            deleteLast();
            break;
        case 9:
            posi = takeIntInput("Enter position to delete the node: ");
            deleteAt(head, posi);
            break;
        case 10:
            val = takeIntInput("Enter value: ");
            update(val);
            break;
        case 11:
            reverse();
            break;
        case 12:
            val = count(head);
            printf("\n\nTotal node is: %d", val);
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

void display(struct Node *node)
{
    if (node == NULL)
    {
        printf("\n\nList is empty.");
        return;
    }
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int count(struct Node *node)
{
    int c = 0;
    while (node != NULL)
    {
        c++;
        node = node->next;
    }
    return c;
}

void insertAtBeg(int data)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = head;
    head = t;
    if (lastNode == NULL)
    {
        lastNode = head;
    }
}

void insert(struct Node *node, int index, int data)
{
    struct Node *t;
    int i;

    int totalNode = count(node);
    if (index < 0 || index > totalNode)
    {
        printf("\n\nThe given position must not exceed the length of the list and must not be less than zero.\n\n");
        return;
    }

    if (index == totalNode)
    {
        insertAtLast(data);
        return;
    }
    if (index == 0)
    {
        insertAtBeg(data);
    }
    else
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = data;
        for (i = 0; i < index - 1; i++)
            node = node->next;
        t->next = node->next;
        node->next = t;
    }
}

/**
 * To recuse the time complexity, we used lastNode variable.
 * Now, time complexity becomes O(1) to add the node at the end.
 */
void insertAtLast(int data)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    if (head == NULL)
    {
        head = lastNode = t;
    }
    else
    {
        lastNode->next = t;
        lastNode = t;
    }
}

int search(int target)
{
    struct Node *node = head;
    while (node != NULL)
    {
        if (target == node->data)
            return true;
        node = node->next;
    }
    return false;
}

void deleteFirst()
{
    struct Node *tmp = head;
    if (tmp == NULL)
    {
        printf("\n\nList is empty.");
        return;
    }
    head = head->next;
    free(tmp);
}
void deleteLast()
{
    int i = 0;
    struct Node *tmp = head;
    if (lastNode == NULL)
    {
        printf("\n\nList is empty.");
        return;
    }
    for (i = 0; i < count(head) - 1; i++)
    {
        tmp = tmp->next;
    }
    lastNode = tmp;
    tmp = tmp->next;
    lastNode->next = NULL;
    free(tmp);
}

void deleteAt(struct Node *node, int index)
{
    struct Node *t;
    int i;

    int totalNode = count(node);

    if (index < 0 || index > totalNode)
    {
        printf("\n\nThe given position must not exceed the length of the list and must not be less than zero.\n\n");
        return;
    }

    if (index == totalNode)
    {
        deleteLast();
        return;
    }
    if (index == 1)
    {
        deleteFirst();
        return;
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            node = node->next;

        t = node->next;
        node->next = t->next;
        free(t);
    }
}

void update(int oldValue)
{
    int n, flag = 0;
    struct Node *tmp = head;

    while (tmp != NULL)
    {
        if (tmp->data == oldValue)
        {
            flag = true;
            break;
        }
        tmp = tmp->next;
    }
    if (flag == true)
    {
        printf("Enter new value: ");
        scanf("%d", &n);
        tmp->data = n;
        printf("\nValue updated.");
    }
    else
    {
        printf("\nInvalid Input\n");
    }
}

void reverse()
{
    struct Node *tmp, *ptr1 = NULL, *ptr2 = NULL;
    tmp = head;
    while (tmp != NULL)
    {
        ptr1 = tmp->next;
        tmp->next = ptr2;
        ptr2 = tmp;
        tmp = ptr1;
    }
    head = ptr2;
}