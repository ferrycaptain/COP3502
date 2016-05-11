#include<stdio.h>
#include<stdlib.h>

// declaring our linked list node, creating a global instance called head
struct node
{
    int data;
    struct node *next;
}*head;

// append function adds a new node at the end of the linked list
void append(int num)
{
    // declaring two instances of node, one for temporary data, and one
    // for traversing the linked list
    struct node *temp,*right;
    // allocating the memory for our node
    temp = (struct node *)malloc(sizeof(struct node));
    // setting the value of attribute data to the value passed in
    temp->data = num;
    // initializing helper node called right to the head of the linked list
    right = (struct node *)head;

    // loop through the linked list until we find the end
    // checks the pointer portion of each node in the linked list
    // if it is equal to NULL we found the end of the linked list
    while(right->next != NULL)
    {
        right = right->next;
    }

    // now update our last node's pointer that equals NULL to now be
    // equal to temp, this is adding temp to the end of the linked list
    right->next = temp;
    // move the helper node to the end of the linked list
    right = temp;
    // update the pointer part of the last node so it is equal to NULL
    // this signifies the end of the linked list
    right->next = NULL;
}

// adding a node to the beginning of the linked list
void add( int num )
{
    // declaring one instances of node temporary data
    struct node *temp;
    // allocating memory for the node
    temp =(struct node *)malloc(sizeof(struct node));
    // set the data portion of our node
    temp->data = num;

    // there isn't a node on the linked list, NULL equals empty
    if (head == NULL)
    {
        // we can just set the head of our linked list to the temporary node
        // the are the same
        head = temp;
        // no nodes follows, only one node at this point, set the pointer to
        // NULL to indicate the end
        head->next = NULL;
    }
    // there at least one node on the linked list,
    else
    {
        // update the next pointer to link to the head of our linked list
        temp->next = head;
        // reset head so it is at the beginning of the linked list, currently
        // that known as temp, setting them equal moves the head to the beginning
        head = temp;
    }
}
// is performing sorting to add the new node
void addafter(int num, int loc)
{
    // declaring three instances of node, one for temporary data, one
    // for traversing the linked list as the left, one for traversing the linked
    // list as the right
    struct node *temp, *left, *right;
    // set the node right equal to the head, the beginning
    right = head;
    // looping through the linked list until we find the
    // location to insert the new node
    for(int i = 1; i < loc; i++)
    {
        // sets left to the right to move both nodes over one position
        // at a time until we find where we need to insert
        left = right;
        printf("position of the linked list %d\n\n", left->data );
        // moving the right node over to the correct location to move
        // towards the insert location
        right = right->next;
    }

    // allocate the memory for the new node
    temp = (struct node *)malloc(sizeof(struct node));
    // set the data portion of the node
    temp->data = num;
    // set the pointer portion of left to equal temp, this adds temp AFTER
    // left
    left->next = temp;
    // move the left over to temp, moving it one position over
    left = temp;
    // update left's next to linked back in the right
    left->next = right;

    return;
}

// determines with function to call to add the new node
// add at the beginning
// add at the end
// add somewhere in the middle
// add somewhere in the middle
void insert(int num)
{
    // counter variable
    int c = 0;
    // temporary pointer for traversing the linked list
    struct node *temp;
    // set the temp equal to head so we start at the beginning
     // of the linked list
    temp = head;
    // it is an empty linked list
    if(temp == NULL)
    {
        // call add to create the node, adds it to the beginning
        add(num);
    }
    // there is at least one other node in the linked list
    // determine where to put the new node
    else
    {
        // traverse the linked list while we don't find the end
        while(temp != NULL)
        {
            // checking the data at each node, to see if this is where we need to
            // insert the new data to be in numeric order
            if(temp->data < num)
            {
                c++;
            }
            // this is where we want to put the data,
            // update the pointer for the next node
            temp = temp->next;
        }
        // if our counter is zero, we are adding to the beginning
        if(c == 0)
            add(num);
        // compare the counter value to the overall size of the linked list
        // if our counter less than the linked list size, call function
        // addafter to insert the node somewhere in the middle of in the linked list
        else if(c < count())
            addafter(num, ++c);
        // if counter is equal to the size of our linked list, append the new
        // node to the end
        else if( c == count())
            append(num);
        // if counter is great than the size of our linked list, we have a
        // problem!
        else if( c > count())
            printf("Something is wrong");
    }
}
// delete the node that has the entered value
int delete(int num)
{
    // delcare two instances of node, temp for the current node, and prev for the
    // node prior to the one we want to delete while traversing the linked list
    struct node *temp, *prev;
    // initialize temp to the head of the linked list
    temp = head;


    // loop until we find the end of the linked list
    while(temp != NULL)
    {
        // compare the data at the current node to the value of the number
        // passed in for deleting
        if(temp->data == num)
        {
            // if temp is equal to head then we are deleting the first node
            // we have update the head pointer before deleting node
            if(temp == head)
            {
                // set the head equal temp->next which is the second node
                // in the linked list
                head = temp->next;
                // this is identical to the code above but uses dot notation
                // instead of pointer notation
                head = (*temp).next;
                // now we can safely delete the node
                free(temp);
                // return value of 1 indicating success
                return 1;
            }
            // not at the beginning of the linked list
            // the node is somewhere else in the linked list
            else
            {
                // update the pointer of prev so it is pointing the next node
                // in the linked list before deleting the temporary node
                prev->next = temp->next;
                // now we can safely delete the node
                free(temp);
                // return value of 1 indicating success
                return 1;
            }
        }
        // we didn't find the value, move the pointers to the next nodes
        // check again by traversing the linked list
        else
        {
            //set prev to the current node
            prev = temp;
            // update temp to be the next node in the linked list
            temp = temp->next;
        }
    }
    // we looked through our linked list and didn't find the value, return
    // a value of 0 to indicate the data didn't exist
    return 0;
}

void  display(struct node *r)
{
    // set the helper node r equal to the beginning of the linked list
    r = head;

    // if r equals NULL we are at the end of the linked list
    if(r == NULL)
    {
        // so just return back to the calling function
        return;
    }

    // while we aren't at the end of the linked list
    while(r != NULL)
    {
        // print out the data stored in node
        printf("%d ", r->data);
        // this is the same as the code above using dot notation instead of
        // pointer notation
        printf("%d ", (*r).data);
        // move my helper node to the next node in the linked list
        r = r->next;

        // if it is NULL, we are at the end of our linked list
        if(r == NULL)
        {
            printf("found the end of our linked list!");

        }
    }

    printf("\n");
}

int count()
{
    // declare a helper node called n
    struct node *n;
    // declare and initialize a counter called c
    int c = 0;
    // set our helper node to the beginning of our linked list
    n = head;

    // loop to traverse our linked list to count how many nodes we have
    while(n != NULL)
    {
        // move our helper node to the next node in the linked list
        n = n->next;
        // increase our counter by one
        c++;
    }

    // return our counter to the calling function
    return c;
}

int  main()
{
    int i, num;
    struct node *n;

    head = NULL;

    while(true)
    {
        printf("\nList Operations\n");
        printf("===============\n");
        printf("1.Insert\n");
        printf("2.Display\n");
        printf("3.Size\n");
        printf("4.Delete\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");

        if(scanf("%d", &i) <= 0)
        {
            printf("Enter only an Integer\n");
            exit(0);
        }
        else
        {

            switch(i)
            {

                case 1:
                    printf("Enter the number to insert : ");
                    scanf("%d", &num);
                    insert(num);
                    break;
                case 2:
                    if(head == NULL)
                    {
                        printf("List is Empty\n");
                    }
                    else
                    {
                        printf("Element(s) in the list are : ");
                    }
                    display(n);
                    break;
                case 3:
                    printf("Size of the list is %d\n",count());
                    break;
                case 4:
                    if(head == NULL)
                        printf("List is Empty\n");
                    else
                    {
                        printf("Enter the number to delete : ");
                        scanf("%d",&num);

                        if(delete(num))
                            printf("%d deleted successfully\n",num);
                        else
                            printf("%d not found in the list\n",num);
                    }
                    break;
                case 5:
                    return 0;
                default:
                    printf("Invalid option\n");
            }
        }
    }

    return 0;
}
