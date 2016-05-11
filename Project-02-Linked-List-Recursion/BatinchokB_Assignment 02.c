#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 80
#define TRUE 1

/* Link list node */
// linked list node definition
struct produceItem
{
    char produce[20];
    char type[20];
    char soldBy[20];
    float price;
    int quantityInStock;
    struct produceItem *next;
    struct produceItem *prev;
};

// function prototypes
void addProduceItem(struct produceItem **, char *, char *, char *, float, int);
void count();
void display(struct produceItem *);
void readDataFile(struct produceItem **);
void recursiveReverse(struct produceItem **);
char * trim(char *c);
void writeDataFile(struct produceItem *);

/* Function to push a node */
void addProduceItem(struct produceItem **headRef, char *produce, char *type, char *soldBy,
                    float price, int quantity)
{
    /* allocate node */
    struct produceItem* temp = (struct produceItem*) malloc(sizeof(struct produceItem));

    /* put in the data  */
    strcpy(temp->produce, produce);
    strcpy(temp->type, type);
    strcpy(temp->soldBy, soldBy);
    temp->price = price;
    temp->quantityInStock = quantity;

    /* link the old list off the new node */
    temp->next = (*headRef);

    /* move the head to point to the new node */
    (*headRef) = temp;
}

/* Function to print linked list */
void display(struct produceItem *headRef)
{
    struct produceItem *helper = headRef;

    if(helper == NULL)
    {
        return;
    }
    else
    {
        printf("==========================================================================\n");
        printf(" Item #   Produce       Type             Sold By         Price    In Stock\n");
        printf("==========================================================================\n");

        int counter = 1;

        while(helper != NULL)
        {
            printf("%5d %3s %-13s %-16s %-13s %6.2f %8d \n",
                   counter++, " ", helper->produce, helper->type,
                   helper->soldBy, helper->price, helper->quantityInStock);

            helper = helper->next;
        }
    }

    printf("\n");
}

// function to read in the data file
void readDataFile(struct produceItem **headRef)
{
    const char comma[2] = ",";
    char dataLine[LENGTH];
    char *produce;
    char *type;
    char *soldBy;
    float price;
    int quantityInStock;
    char *fileName = "AssignmentTwoInput.txt";
    FILE *filePointer;

    printf("Trying to open file %s\n", fileName);
    filePointer = fopen(fileName, "r"); // read mode
    printf("Successfully opened file %s\n", fileName);

    if( filePointer == NULL )
    {
        perror("Error while opening the file.\n");
        exit(0);
    }


    // loop until find end of file
    while( fgets(dataLine, LENGTH, filePointer) != NULL)
    {
        // string tokenize the data line to get the individual fields
        produce = trim(strtok(dataLine, ","));
        type = trim(strtok(NULL, ","));
        soldBy = trim(strtok(NULL, ","));
        price = atof(trim(strtok(NULL, ",")));
        quantityInStock = atoi(trim(strtok(NULL, ",")));

        addProduceItem(headRef, produce, type, soldBy, price, quantityInStock);
    }

    fclose(filePointer);
}

void recursiveReverse(struct produceItem** head_ref)
{
    struct produceItem* first;
    struct produceItem* rest;

    /* empty list */
    if (*head_ref == NULL)
       return;

    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;
    rest  = first->next;

    /* List has only one node */
    if (rest == NULL)
       return;

    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;

    /* tricky step -- see the diagram */
    first->next = NULL;

    /* fix the head pointer */
    *head_ref = rest;
}

char * trim(char *c)
{
    char * e = c + strlen(c) - 1;

    while(*c && isspace(*c))
        c++;

    while(e > c && isspace(*e))
        *e-- = '\0';

    return c;
}

void writeDataFile(struct produceItem *headRef)
{
    char *fileName = "AssignmentTwoOutput.txt";
    FILE *filePointer;
    int counter = 1;
    struct produceItem *helper = headRef;


    printf("Trying to create file %s\n", fileName);
    filePointer = fopen(fileName, "w"); // write mode

    if( filePointer == NULL )
    {
        perror("Error while opening the file.\n");
        exit(0);
    }

    if(helper == NULL)
    {
        return;
    }
    else
    {
        fprintf(filePointer, "==========================================================================\n");
        fprintf(filePointer, " Item #   Produce       Type             Sold By         Price    In Stock\n");
        fprintf(filePointer, "==========================================================================\n");

        while(helper != NULL)
        {
            fprintf(filePointer, "%5d %3s %-13s %-16s %-13s %6.2f %8d \n",
                   counter++, " ", helper->produce, helper->type,
                   helper->soldBy, helper->price, helper->quantityInStock);

            helper = helper->next;
        }
    }

    fclose(filePointer);
    printf("Successfully wrote out file %s", fileName);
}

int main()
{
    int choice = 0;
    /* Start with the empty list */
    struct produceItem * head = NULL;

    // loop until the user wants to exit
    while(TRUE)
    {
        printf("\nList Operations\n");
        printf("===============\n");
        // this option reads in the data file and creates a linked list
        printf("1. Stock Produce Department\n");
        // this option displays to the screen the produce inventory
        printf("2. Display Produce Inventory\n");
        // this option recursively reverses the inventory
        printf("3. Reverse Order of Produce Inventory\n");
        // this option writes to a file the produce inventory
        printf("4. Export Produce Inventory\n");
        // this option exits the program
        printf("5. Exit Program\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);
//        if(scanf("%d", &choice) <= 0)
//        {
//            printf("Enter only an Integer\n");
//            exit(0);
//        }
//        else
//        {
            switch(choice)
            {
                case 1:
                    readDataFile(&head);
                    break;
                case 2:
                    display(head);
                    break;
                case 3:
                    recursiveReverse(&head);
                    break;
                case 4:
                    writeDataFile(head);
                    break;
                case 5:
                    return 0;
                default:
                    printf("Invalid option\n");
            }
//        }
    }

    return 0;

    display(head);
}

